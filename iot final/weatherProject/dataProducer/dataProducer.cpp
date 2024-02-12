#include "dataProducer.h"


DataProducer::DataProducer(int seed) {
	srand(seed);
	temperature = ProduceTemperature(0);
	humidity = ProduceHumidity(0);
	UVindex = ProduceUV(0);
	cloudiness = ProduceCloudiness(0);
	windSpeed = produceWindSpeed(0);
	windDirection = rand() % 8 + 1;
}

void DataProducer::produce(WeatherData* data) {
	switch (timer % MAXCIRCLETIME) {
	case 0:
		refreshRoundOne(data);
		break;
	case 1:
		refreshRoundTwo(data);
		break;
	case 2:
		refreshRoundThree(data);
		break;
	}
	timer = (timer + 1) % MAXCIRCLETIME;
}

int DataProducer::getTemperature()	{ return temperature; }
int DataProducer::getHumidity()		{ return humidity; }
int DataProducer::getUVindex()		{ return UVindex; }
int DataProducer::getCloudiness()	{ return cloudiness; }
int DataProducer::getWindSpeed()	{ return windSpeed; }
int DataProducer::getWindDirection(){ return windDirection; }

int DataProducer::ProduceTemperature(int oldTemp, int minTemp, int maxTemp) {
	int newTemp = oldTemp + int((rand() % (maxTemp - minTemp) + minTemp)*0.1);
	return newTemp;

	//return int((rand() % (maxTemp - minTemp) + minTemp));
}

int DataProducer::ProduceHumidity(int oldHum) {
	int newHum = oldHum + int((rand() % 201 - 100) * 0.05);
	if (newHum >= 100) newHum -= 5;
	else if (newHum < 0) newHum += 5;
	return newHum;

	//return int(rand() % 101);
}

int DataProducer::ProduceUV(int cloudiness) {
	if (cloudiness < 40)
		return rand() % 3 + 4;
	else
		return rand() % 4;
}

int DataProducer::ProduceCloudiness(int oldCloudiness) {
	int newCloud = oldCloudiness + int((rand() % 201 - 100) * 0.1);
	if (newCloud >= 100) newCloud -= 10;
	else if (newCloud < 0) newCloud += 10;
	return newCloud;

	//return int(rand() % 101);
}

int DataProducer::produceWindSpeed(int oldSpeed) {
	int newSpeed = oldSpeed + int((rand() % 70 - 35) * 0.1);
	if (newSpeed >= 35) newSpeed -= 5;
	else if (newSpeed < 0) newSpeed += 5;
	return newSpeed;

	//return int(rand() % 15);
}

int DataProducer::produceWindDirection() {
	int rnd = rand() / RAND_MAX;
	if (rnd < 0.2) { 
		if (windDirection == 1) return 8;
		return int((windDirection - 1) % 8); 
	}
	if (rnd < 0.8) { return windDirection; }
	if (windDirection == 7) return 8;
	return int((windDirection + 1) % 8);
	// ukljuci enum iz proto klase
}

void DataProducer::refreshRoundOne(WeatherData* newData) {
	temperature = ProduceTemperature(temperature);
	humidity = ProduceHumidity(humidity);
	cloudiness = ProduceCloudiness(cloudiness);
	UVindex = ProduceUV(cloudiness);
	windSpeed = produceWindSpeed(windSpeed);
	windDirection = produceWindDirection();

	newData->set_temperature(temperature);
	newData->set_humidity(humidity);
	newData->set_cloudcover(cloudiness);
	newData->set_uvindex(UVindex);
	newData->set_windspeed(windSpeed);
	newData->set_winddirection(static_cast<WindDir>(windDirection));
}

void DataProducer::refreshRoundTwo(WeatherData* newData) {
	temperature = ProduceTemperature(temperature);
	cloudiness = ProduceCloudiness(cloudiness);
	UVindex = ProduceUV(cloudiness);
	windSpeed = produceWindSpeed(windSpeed);
	windDirection = produceWindDirection();

	newData->set_temperature(temperature);
	newData->set_cloudcover(cloudiness);
	newData->set_uvindex(UVindex);
	newData->set_windspeed(windSpeed);
	newData->set_winddirection(static_cast<WindDir>(windDirection));
}

void DataProducer::refreshRoundThree(WeatherData* newData) {
	temperature = ProduceTemperature(temperature);
	humidity = ProduceHumidity(humidity);
	cloudiness = ProduceCloudiness(cloudiness);
	UVindex = ProduceUV(cloudiness);

	newData->set_temperature(temperature);
	newData->set_humidity(humidity);
	newData->set_cloudcover(cloudiness);
	newData->set_uvindex(UVindex);
}

