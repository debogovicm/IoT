#include <ctime>

#include "dataProcessor.h"
#include "weatherData.pb.h"

DataProcessor::DataProcessor(string topic_name) {
	subscriber = Subscriber::getSubscriber(topic_name); // razmisli da li sub treba da bude singlton -> mislim da ne
	databaseConnection();
}

void DataProcessor::messageCollector() {
	long long startTime = (long long)time(0);
	while ((long long)time(0) - startTime < TIME_STEP) { 
		messages.push_back(subscriber->getMessage());
	}
}

void DataProcessor::processing() {
	map<string, WeatherData*> mapMessage;
	map<string, int*> mapCount;

	for (auto msg: messages) {
		string topic_name = msg->get_topic();
		WeatherData* dataOut = new WeatherData();
		dataOut->ParseFromString(msg->to_string());
		//std::cout << topic_name << "\n" << dataOut->DebugString() << std::endl;

		if (mapCount.find(topic_name) == mapCount.end()) {
			int* zeros = new int[6]{ 0, 0, 0, 0, 0, 0 };
			WeatherData* mapData = new WeatherData();
			mapCount.insert({ topic_name, zeros});
			mapMessage.insert({ topic_name, mapData });
		}
		accumulateData(mapMessage[topic_name], dataOut, mapCount[topic_name]);
		delete(dataOut);
	}

	for (auto const &m : mapMessage) {
		string topic = m.first;
		WeatherData* data = m.second;
		averagedData(data, mapCount[topic]);
		insertIntoDatabase(topic, data);

		// ispis za proveru
		std::cout << topic << std::endl;
		std::cout << data->DebugString() << std::endl << std::endl;
	}

	messages.erase(messages.begin(), messages.end());
	std::cout << "*********************************************************************************************" << std::endl;
}


void DataProcessor::accumulateData(WeatherData* accMsg, WeatherData* newMsg, int* counter) {
	if (newMsg->has_temperature()) {
		accMsg->set_temperature(accMsg->temperature() + newMsg->temperature());
		counter[0]++;
	}
	if (newMsg->has_humidity()) {
		accMsg->set_humidity(accMsg->humidity() + newMsg->humidity());
		counter[1]++;
	}
	if (newMsg->has_cloudcover()) {
		accMsg->set_cloudcover(accMsg->cloudcover() + newMsg->cloudcover());
		counter[2]++;
	}
	if (newMsg->has_uvindex()) {
		accMsg->set_uvindex(accMsg->uvindex() + newMsg->uvindex());
		counter[3]++;
	}
	if (newMsg->has_windspeed()) {
		accMsg->set_windspeed(accMsg->windspeed() + newMsg->windspeed());
		counter[4]++;
	}
	if (static_cast<int>(newMsg->winddirection()) != 0) {
		accMsg->set_winddirection(static_cast<WindDir>(static_cast<int>(accMsg->winddirection()) + static_cast<int>(newMsg->winddirection())));
		counter[5]++;
	}
}

void DataProcessor::averagedData(WeatherData* accMsg, int* counter) {
	if (counter[0]) accMsg->set_temperature((int)(accMsg->temperature() / counter[0]));
	if (counter[1]) accMsg->set_humidity((int)(accMsg->humidity() / counter[1]));
	if (counter[2]) accMsg->set_cloudcover((int)(accMsg->cloudcover() / counter[2]));
	if (counter[3]) accMsg->set_uvindex((int)(accMsg->uvindex() / counter[3]));
	if (counter[4]) accMsg->set_windspeed((int)(accMsg->windspeed() / counter[4]));
	if (counter[5]) accMsg->set_winddirection(static_cast<WindDir>(static_cast<int>(accMsg->winddirection() / counter[5])));
}

void DataProcessor::databaseConnection() {
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	con->setSchema("WeatherDatabase");
	pstmt = con->prepareStatement("INSERT INTO WeatherData(city, temperature, UVindex, humidity, cloudCover, windSpeed, windDirection) VALUES(?,?,?,?,?,?,?)");
}

void DataProcessor::insertIntoDatabase(string topic, WeatherData* data) {
	pstmt->setInt(1, stoi(topic.substr(5, 4)));
	pstmt->setInt(2, data->temperature());
	pstmt->setInt(3, data->uvindex());
	pstmt->setInt(4, data->humidity());
	pstmt->setInt(5, data->cloudcover());
	pstmt->setInt(6, data->windspeed());
	pstmt->setInt(7, data->winddirection());
	pstmt->execute();
}


