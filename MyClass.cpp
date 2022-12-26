#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Input3.h"
#include "MyClassHeader.h"

Talk::Talk() {
	date = "?";
	city_code = "?";
	city_name = "?";
	talk_time = "?";
	tariff = "?";
	caller_number = "?";
	subscriber_number = "?";
}
void Talk::print(int i) {
	std::cout << "|| " << std::setw(2) << i << " | "
		<< date << " | "
		<< city_code << "      | "
		<< city_name << " | "
		<< talk_time << " | "
		<< tariff << " | +"
		<< caller_number << "     | +"
		<< subscriber_number << "     ||\n";
}
void Talk::create() {
	//std::string test_data = input_date();
	date = input_date();

	//std::string test_city_code = input_city_code();
	city_code = input_city_code();

	//std::string test_city_name = input_city_name();
	city_name = input_city_name();

	//std::string test_talk_time = input_talk_time();
	talk_time = input_talk_time();

	//std::string test_tariff = input_tariff();
	tariff = input_tariff();

	//std::string test_caller_number = input_number(0);
	caller_number = input_number(0);

	//std::string test_subscriber_number = input_number(1);
	subscriber_number = input_number(1);
}
void Talk::clear() {
	date = "?";
	city_code = "?";
	city_name = "?";
	talk_time = "?";
	tariff = "?";
	caller_number = "?";
	subscriber_number = "?";
}
void Talk::change(int field) {
	switch (field) {
	case 1: {
		std::string new_date = input_date();
		date = new_date;
		break;
	}
	case 2: {
		std::string new_city_code = input_city_code();
		city_code = new_city_code;
		break;
	}
	case 3: {
		std::string new_city_name = input_city_name();
		city_name = new_city_name;
		break;
	}
	case 4: {
		std::string new_talk_time = input_talk_time();
		talk_time = new_talk_time;
		break;
	}
	case 5: {
		std::string new_tariff = input_tariff();
		tariff = new_tariff;
		break;
	}
	case 6: {
		std::string new_caller_number = input_number(0);
		caller_number = new_caller_number;
		break;
	}
	case 7: {
		std::string new_subscriber_number = input_number(1);
		subscriber_number = new_subscriber_number;
		break;
	}
	}
}
bool Talk::isexist() {
	if (date == "?" && city_code == "?" && city_name == "?" && talk_time == "?"
		&& tariff == "?" && caller_number == "?" && subscriber_number == "?")
		return false;
	return true;
}
void Talk::push(int i) {
	std::fstream file("file.bin", std::ios::binary | std::ios::in | std::ios::out);
	if (!file.is_open())
		throw 0;
	std::cout << "before: " << file.tellp() << "\n";
	file.seekp(i * sizeof(*this), std::ios::beg);
	std::cout << "after: " << file.tellp() << "\n";

	file.write((char*)this, sizeof(*this));
	file.close();
}
void Talk::pop(int i) {
	std::ifstream file("file.bin", std::ios::binary);
	if (!file.is_open())
		throw 0;
	file.seekg(i * sizeof(*this), std::ios::beg);
	file.read((char*)this, sizeof(*this));
	file.close();
}