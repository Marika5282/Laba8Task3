#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "InputHeader.h"
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
	date = input_date();
	city_code = input_city_code();
	city_name = input_city_name();
	talk_time = input_talk_time();
	tariff = input_tariff();
	caller_number = input_number(0);
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
	enum { DATE = 1, CITY_CODE, CITY_NAME, TALK_TIME, TARIFF, CALLER_NUMBER, SUBSCRIBER_NUMBER };
	switch (field) {
	case DATE: {
		std::string new_date = input_date();
		date = new_date;
		break;
	}
	case CITY_CODE: {
		std::string new_city_code = input_city_code();
		city_code = new_city_code;
		break;
	}
	case CITY_NAME: {
		std::string new_city_name = input_city_name();
		city_name = new_city_name;
		break;
	}
	case TALK_TIME: {
		std::string new_talk_time = input_talk_time();
		talk_time = new_talk_time;
		break;
	}
	case TARIFF: {
		std::string new_tariff = input_tariff();
		tariff = new_tariff;
		break;
	}
	case CALLER_NUMBER: {
		std::string new_caller_number = input_number(0);
		caller_number = new_caller_number;
		break;
	}
	case SUBSCRIBER_NUMBER: {
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
	file.seekp(i * sizeof(*this), std::ios::beg);
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