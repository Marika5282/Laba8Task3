#include <iostream>
#include <string>
#include <filesystem>
#include "InputHeader.h"
#include "MyClassHeader.h"
#include "UtilityHeader.h"

const int AMOUNT = 200;
namespace sf = std::filesystem;
void push_all(MyPair Records, int begin) {
	Talk* list = Records.first;
	int size = Records.second;

	int amount; // amount of existing elements
	for (amount = 0; amount < size; amount++) {
		if (!list[amount].isexist())
			break;
	}
	for (int i = begin; i < amount; i++) {
		list[i].push(i);
	}
}
void print_all(MyPair Records) {
	int counter = 0;
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "|| No | Date       | City code | City name       | Talk time | Tariff         | Caller number     | Subscriber number ||\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < Records.second; i++) {
		if (Records.first[i].isexist()) {
			Records.first[i].print(i + 1);
			counter++;
		}
	}
	if (!counter)
		std::cout << "||                                                     No records                                                     ||\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
}
int binsearch(Talk* list, Talk key, int begin, int end) {
	if (begin == end - 1) return begin;
	int mid = (begin + end) / 2;
	if (key.get_date() < list[mid].get_date())
		return binsearch(list, key, begin, mid);
	else
		return binsearch(list, key, mid, end);
}
void renew(Talk*& list, int old_amount, int new_amount) {
	Talk* new_list = new Talk[new_amount];
	for (int i = 0; i < old_amount; i++) {
		new_list[i] = list[i];
	}
	delete[] list;
	list = new_list;
	//return new_list;
}
void insert(MyPair Records, int amount, Talk newtalk, int pos) {
	int size = Records.second;
	Talk* list = Records.first;

	if (amount == size) {
		size += AMOUNT;
		renew(list, amount, size);
	}
	for (int i = amount - 1; i >= pos; i--) {
		list[i + 1] = list[i];
	}
	list[pos] = newtalk;
}
void create_one(MyPair Records) {
	Talk newtalk;
	newtalk.create();

	int size_records = Records.second;

	Talk newtalk_date, list_last_date, list_first_date;
	int amount; // amount of existing elements
	for (amount = 0; amount < size_records; amount++) {
		if (!Records.first[amount].isexist()) {
			break;
		}
	}

	int pos;
	if (amount == 0) {
		pos = 0;
	}
	else {
		newtalk_date = newtalk;
		list_last_date = Records.first[amount - 1];
		list_first_date = Records.first[0];

		if (newtalk_date.get_date() >= list_last_date.get_date())
			pos = amount;
		else if (newtalk_date.get_date() <= list_first_date.get_date())
			pos = 0;
		else
			pos = binsearch(Records.first, newtalk, 0, amount - 1);
	}
	insert(Records, amount, newtalk, pos);
	push_all(Records, pos);
}
void create_several(MyPair Records) {
	int amount_of_new_records = enter_positive_whole_number(100, "Enter the amount of records you want to enter: ");

	for (int i = 0; i < amount_of_new_records; i++) {
		create_one(Records);
	}
}
int change(MyPair Records) {
	Talk* list = Records.first;
	int size = Records.second;

	int field_number, talk_number;
	int amount; // amount of existing elements
	std::string talk_number_str;

	for (amount = 0; amount < size; amount++) {
		if (!list[amount].isexist())
			break;
	}
	if (amount == 0) {
		std::cout << "No records.\n";
		return 0;
	}
	std::cout << "Choose # talk:\n";
	print_all(Records);
	talk_number = (int)enter_positive_whole_number(amount, "Enter # talk: ");
	field_number = input_field_number();
	talk_number--;
	list[talk_number].change(field_number);
	list[talk_number].push(talk_number);
	print_all(Records);
	return talk_number;
}
void delete_one(MyPair Records) {
	Talk* list = Records.first;
	int size = Records.second;

	int amount; // amount of existing elements

	for (amount = 0; amount < size; amount++) {
		if (!list[amount].isexist())
			break;
	}
	if (amount == 0) {
		std::cout << "No records.\n";
		return;
	}
	int talk_number = (int)enter_positive_whole_number(amount, "Enter # talk you want to delete: ");
	talk_number--;
	for (int i = talk_number; i < amount; i++) {
		list[i] = list[i + 1];
	}
	list[amount - 1].clear();

	push_all(Records, talk_number);

	sf::resize_file("file.bin", sf::file_size("file.bin") - 280);
}
MyPair pop_all() {
	int famount = sf::file_size("file.bin") / 280;
	int size = ((famount % AMOUNT) ? (((famount / AMOUNT) + 1) * AMOUNT) : (famount));
	//int size = famount;
	if (size == 0) {
		size += AMOUNT;
		Talk* list = new Talk[size];
		return { list, size };
	}
	Talk* list = new Talk[size];
	for (int i = 0; i < famount; i++) {
		list[i].pop(i);
	}
	return { list, size };
}
