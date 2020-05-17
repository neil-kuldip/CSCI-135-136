/*
Author: Neil Kuldip
Course; CSCI-135
Instructor: Genady Maryash
Assignment: Homework E9.3 - Light Switch

The program simulates a circuit for controlling a hallway light that has switches at both ends of the hallway.
Each switch can be up or down, and the light can be on or off. Toggling either switch turns the lamp on or off.
*/
#include <iostream>
using namespace std;

class Circuit {
public:
	int get_first_switch_state(); //0 for down, 1 for up
	int get_second_switch_state();
	int get_lamp_state(); //0 for off, 1 for on
	void toggle_first_switch();
	void toggle_second_switch();
private:
	int first_switch_value = 0;
	int second_switch_value = 0;
	int lamp_value = 0;
};

int Circuit::get_first_switch_state()
{
	int value = first_switch_value;
	return value;
}

int Circuit::get_second_switch_state()
{
	int value = second_switch_value;
	return value;
}

int Circuit::get_lamp_state()
{
	int value = lamp_value;
	return value;
}

void Circuit::toggle_first_switch()
{
	if (first_switch_value == 0)
	{
		first_switch_value = 1; //First switch flicks up
	}
	else if (first_switch_value == 1)
	{
		first_switch_value = 0; //First switch flicks down
	}

	//Conditions for lamp light
	if (first_switch_value == second_switch_value)
	{
		lamp_value = 0; //Lamp light is off
	}
	else if (first_switch_value != second_switch_value)
	{
		lamp_value = 1; //Lamp light is on
	}
}

void Circuit::toggle_second_switch()
{
	if (second_switch_value == 0)
	{
		second_switch_value = 1; //Second switch flicks up
	}
	else if (second_switch_value == 1)
	{
		second_switch_value = 0; //Second switch flicks down
	}

	//Conditions for lamp light
	if (first_switch_value == second_switch_value)
	{
		lamp_value = 0; //Lamp light is off
	}
	else if (first_switch_value != second_switch_value)
	{
		lamp_value = 1; //Lamp light is on
	}
}

int main()
{
	Circuit hallway;
	cout << hallway.get_lamp_state(); //Lamp should be off
	hallway.toggle_first_switch(); //F1
	cout << hallway.get_lamp_state(); //Lamp should be on
	hallway.toggle_second_switch(); //S1
	cout << hallway.get_lamp_state(); //Lamp should turn off
	hallway.toggle_second_switch(); //S0
	cout << hallway.get_lamp_state(); //Lamp should turn on
	hallway.toggle_first_switch(); //F0
	cout << hallway.get_lamp_state(); //Lamp should turn off
}