/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab Quiz #12

This program contains class Customer
*/

#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
	string name;
	string unique_id;
public:
	Customer();
	Customer(string name, string unique_id);
	string get_name();
	string get_unique_id();
	void set_name(string input_name);
	void set_unique_id(string input_unique_id);
};

Customer::Customer(string input_name, string input_unique_id)
{
	name = input_name;
	unique_id = input_unique_id;
}

Customer::Customer()
{
	name = "";
	unique_id = "";
}

string Customer::get_name()
{
	return name;
}

string Customer::get_unique_id()
{
	return unique_id;
}

void Customer::set_name(string input_name)
{
	name = input_name;
}

void Customer::set_unique_id(string input_unique_id)
{
	unique_id = input_unique_id;
}

