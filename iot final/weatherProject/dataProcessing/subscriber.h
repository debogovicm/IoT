#ifndef  SUBSCRIBER_H
#define SUBSCRIBER_H

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

class Subscriber {
private:
	const std::string DFLT_ADDRESS{ "tcp://localhost:1883" };
	//const string TOPIC{ "data/rand" };
	const int	 QOS = 1;
	const seconds PERIOD = seconds(5); // auto -> seconds
	const int MAX_BUFFERED_MSGS = 120;	// 120 * 5sec => 10min off-line buffering

	static Subscriber* instance;
	mqtt::async_client* client = nullptr;


	Subscriber(string topic_name);

public:
	Subscriber(const Subscriber&) = delete;
	static Subscriber* getSubscriber(string topic_name);
	mqtt::const_message_ptr getMessage();

};

#endif // ! SUBSCRIBER_H
