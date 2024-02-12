#include "publisher.h"

Publisher* Publisher::instance = nullptr;

Publisher::Publisher() {
	client = new mqtt::async_client(DFLT_ADDRESS, "pub", MAX_BUFFERED_MSGS); // PERSIST_DIR
	
	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(MAX_BUFFERED_MSGS * PERIOD);
	connOpts.set_clean_session(true);
	connOpts.set_automatic_reconnect(true);
	try {
		client->connect(connOpts)->wait();
	} 
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		exit(1);
	}
	
}


Publisher* Publisher::getPublisher() {
    if (instance == nullptr) {
        instance = new Publisher();
	}
	return instance;	
}

mqtt::topic Publisher::newTopic(string port) {
	string topicName = "city/" + port;
	return	mqtt::topic(*client, topicName, QOS, true);
}
