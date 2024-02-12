#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <string>
#include <vector>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "subscriber.h"
#include "weatherData.pb.h"
#define TIME_STEP 5

using namespace std;

class DataProcessor {
public:
	DataProcessor(string topic_name);
	void messageCollector();
	void processing();

private:
	Subscriber* subscriber;
	vector<mqtt::const_message_ptr> messages;

	// komunikascija sa bazom
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	const string server = "tcp://127.0.0.1:3306";
	const string username = "root";
	const string password = "123123";

	void accumulateData(WeatherData*, WeatherData*, int*);
	void averagedData(WeatherData*, int*);
	void databaseConnection();
	void insertIntoDatabase(string topic, WeatherData* data);
};

#endif