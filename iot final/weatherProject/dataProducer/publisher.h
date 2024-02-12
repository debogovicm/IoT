#ifndef  PUBLISHER_H
#define PUBLISHER_H

#include <random>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "mqtt/async_client.h"

using namespace std;
using namespace std::chrono;

class Publisher {
private:
	const std::string DFLT_ADDRESS{ "tcp://localhost:1883" };
	//const string TOPIC{ "data/rand" };
	const int	 QOS = 1;
	const seconds PERIOD = seconds(5); // auto -> seconds
	const int MAX_BUFFERED_MSGS = 120;	// 120 * 5sec => 10min off-line buffering

	static Publisher* instance;
	mqtt::async_client* client = nullptr;


	Publisher();

public:
	Publisher(const Publisher&) = delete;
	static Publisher* getPublisher();
	mqtt::topic newTopic(string port);
	

};

#endif // ! PUBLISHER_H
