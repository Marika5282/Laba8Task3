#pragma once

class Talk {
private:
	std::string date;
	std::string city_code;
	std::string city_name;
	std::string talk_time;
	std::string tariff;
	std::string caller_number;
	std::string subscriber_number;
public:
	std::string get_date() { return date; }
	std::string get_city_code() { return city_code; }
	std::string get_city_name() { return city_name; }
	std::string get_talk_time() { return talk_time; }
	std::string get_tariff() { return tariff; }
	std::string get_caller_number() { return caller_number; } // кто звонит
	std::string get_subscriber_number() { return subscriber_number; } // кому звонят

	Talk();
	~Talk() {};
	void print(int i);
	void create();
	void clear();
	void change(int field);
	bool isexist();
	void push(int i);
	void pop(int i);
};
