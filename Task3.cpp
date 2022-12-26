#include <iostream>
#include <string>
#include "InputHeader.h"
#include "MyClassHeader.h"
#include "UtilityHeader.h"

typedef std::pair <Talk*, int> MyPair;

void menu(MyPair& Records) {
	enum { PRINT_ALL = 1, CREATE_ONE, CREATE_SEVERAL, CHANGE, DELETE_ONE };
	int choice, changed_element;
	choice = input_choice();

	switch (choice) {
	case PRINT_ALL: {
		print_all(Records);
		break;
	}
	case CREATE_ONE: {
		create_one(Records);
		break;
	}
	case CREATE_SEVERAL: {
		create_several(Records);
		break;
	}
	case CHANGE: {
		change(Records);
		break;
	}
	case DELETE_ONE: {
		delete_one(Records);
		break;
	}
	}
}

int main() {
	MyPair Records = pop_all();

	while (1) {
		try {
			menu(Records);
		}
		catch (const int) {
			std::cout << "Unable to open file.\n";
			return EXIT_FAILURE;
		}
	}

	delete[] Records.first;

	return 0;
}