#pragma once
typedef std::pair <Talk*, int> MyPair;
void print_all(MyPair Records);
void create_one(MyPair Records);
void create_several(MyPair Records);
int change(MyPair Records);
void delete_one(MyPair Records);
MyPair pop_all();