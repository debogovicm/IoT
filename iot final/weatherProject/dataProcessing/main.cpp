#include "dataProcessor.h"
#include "subscriber.h"
#include "weatherData.pb.h"

int main() {
	
	string topic_name = "city/#";
	DataProcessor* dataProc = new DataProcessor(topic_name);

	while (true) {
		/*mqtt::const_message_ptr msg = Subscriber::getSubscriber(topic_name)->getMessage();

		WeatherData* dataOut = new WeatherData();
		dataOut->ParseFromString(msg->to_string());
		std::cout << msg->get_topic() << "\n" << dataOut->DebugString() << std::endl;
		delete dataOut;
		*/

		dataProc->messageCollector();
		dataProc->processing();
	}
	/*
	WeatherData* dataOut = new WeatherData();
	dataOut->set_uvindex(1);
	std::cout << dataOut->has_temperature() << std::endl;
	std::cout << dataOut->has_uvindex() << std::endl;
*/
}