#define NOMINMAX

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

#include "dataProducer.h"
#include "publisher.h"
#include "weatherData.pb.h"

void threadFunction(std::string name, std::string port) {
	DataProducer* dataProd = new DataProducer(stoi(port));
	mqtt::topic topic = Publisher::getPublisher()->newTopic(port);
	while (1) {
		//RELEASE MODE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		WeatherData* data = new WeatherData();
		dataProd->produce(data);
		std::string content;
		data->SerializeToString(&content);
		delete data;
		Sleep(500);

		// slanje na topic
		topic.publish(std::move(content));
		
		WeatherData* dataOut = new WeatherData();
		dataOut->ParseFromString(content);
		//std::cout << name << "\n" << dataOut->DebugString() << std::endl;
		//topic.publish(std::move(content));

		delete dataOut;
	}
}

int main() {
	std::vector<std::string> cities = { "Belgrade", "London", "New York"};
	std::vector<std::string> ports = { "5556", "5557", "5558" };
	std::vector<std::thread> threads;

	for (int i = 0; i < cities.size(); i++) {
		std::thread thr(threadFunction, cities[i], ports[i]);
		threads.push_back(move(thr));
	}

	for (auto& thr : threads)
		thr.join();
}