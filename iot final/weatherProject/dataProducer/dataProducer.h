#ifndef DATAPRODUCER
#define DATAPRODUCER

#define MAXCIRCLETIME 3
#define SLEEPSTEP 200 //ms

#include "weatherData.pb.h"

class DataProducer {
public:
	DataProducer(int);

	void produce(WeatherData*);
	//WeatherData* deliver();

	//mozda ne trebaju
	int getTemperature();
	int getHumidity();
	int getUVindex();
	int getCloudiness();
	int getWindSpeed();
	int getWindDirection();


private:
	int temperature;
	int humidity;
	int UVindex;
	int cloudiness;
	int windSpeed;
	int windDirection;
	int timer = 0;

	int ProduceTemperature(int oldTemp, int minTemp = -45, int maxTemp = 45);
	int ProduceHumidity(int oldHum);
	int ProduceUV(int cloudiness);
	int ProduceCloudiness(int oldCloudiness);
	int produceWindSpeed(int oldSpeed);
	int produceWindDirection();

	void refreshRoundOne(WeatherData*);
	void refreshRoundTwo(WeatherData*);
	void refreshRoundThree(WeatherData*);
	//napravi razlicite kombinacije
	// ideja je da se ne azuriraju svi podaci podjednako cesto,
	// pa se ne moraju podjednako cesto ni slati


	// ubaciti slucajne greske!!

public:

	
};

#endif