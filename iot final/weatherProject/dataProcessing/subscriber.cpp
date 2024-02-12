#include "subscriber.h"

Subscriber* Subscriber::instance = nullptr;

Subscriber::Subscriber(string topic_name) {
	client = new mqtt::async_client(DFLT_ADDRESS, "sub", MAX_BUFFERED_MSGS); // PERSIST_DIR

	
	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(MAX_BUFFERED_MSGS * PERIOD);
	connOpts.set_clean_session(true);
	connOpts.set_automatic_reconnect(true);
	try {
		client->start_consuming();
		client->connect(connOpts)->wait();

		auto TOPICS = mqtt::string_collection::create({ topic_name });
		client->subscribe(TOPICS, { QOS });

	} 
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		exit(1);
	}
	
}


Subscriber* Subscriber::getSubscriber(string topic_name) {
    if (instance == nullptr) {
        instance = new Subscriber(topic_name);
	}
	return instance;	
}

mqtt::const_message_ptr Subscriber::getMessage() {
	auto msg = client->consume_message();
	// razmislite sta se desava kada je poruka null
	return msg;
}

