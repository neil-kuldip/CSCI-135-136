/*
Author: Neil Kuldip
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3
This source file contains the functions that program the robots’ logic so they do their work more efficiently
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "bot.h"
using namespace std;

const int MAX_ROBOT_NUM = 50;

//Added derbis tools
const int MAX_ROWS = 40;
const int MAX_COLS = 40;
bool debris[MAX_ROWS][MAX_COLS]; //Bool array for location of debris

//Added robot detection tools
int robot[MAX_ROWS][MAX_COLS]; //Array for generated robots
int nursebot[MAX_ROBOT_NUM]; //Helper bot
bool working[MAX_ROBOT_NUM]; //Is the robot in good condition?

//Designated task functions
Action collectDebris(int id, Loc loc, Area& area, ostream& log);
void findMyNurse(int id, Loc loc, Area& area, ostream& log);
Action repairWork(int id, Loc loc, Area& area, ostream& log);


int NUM;          // to remember number of robots
int ROWS, COLS;   // map dimensions
int DAMAGE_RATE;  // to record malfunctioning probability

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
	Area& area, ostream& log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	DAMAGE_RATE = mpr;

	//Updating debris array to generated map
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (area.inspect(i, j) == DEBRIS)
			{
				debris[i][j] = true;
			}
			else
			{
				debris[i][j] = false;
			}
			robot[i][j] = -1; //Initalizing robot array
		}
	}

	//Updating robot arrays to generated map
	for (int i = 0; i < NUM; i++)
	{
		int robo_row = area.locate(i).r; //Row of generated robot
		int robo_col = area.locate(i).c; //Column of generated robot
		robot[robo_row][robo_col] = i; //Updating array to robot coordinates
		nursebot[i] = -1; //Setting nurse robots to nothing 
		working[i] = true; //All robot are in stable condition 
	}

	log << "Start!" << endl;
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area& area, ostream& log)
{
	robot[area.locate(id).r][area.locate(id).c] = id;
	int row = loc.r; // current row and column
	int col = loc.c;

	if (working[id] == false)
	{
		return COLLECT;
	}
	if (nursebot[id] != -1)
	{
		robot[area.locate(nursebot[id]).r][area.locate(nursebot[id]).c] = nursebot[id];
		robot[area.locate(id).r][area.locate(id).c] = -1;
		robot[row][col] = id;
		return repairWork(id, loc, area, log);
	}
	else
	{
		if (area.inspect(row, col) == DEBRIS)
		{
			robot[area.locate(id).r][area.locate(id).c] = -1;
			robot[row][col] = id;
			return COLLECT;
		}
		else
		{
			robot[area.locate(id).r][area.locate(id).c] = -1;
			robot[row][col] = id;
			return collectDebris(id, loc, area, log);
		}
	}
}

Action collectDebris(int id, Loc loc, Area& area, ostream& log)
{
	int row = loc.r; // current row and column
	int col = loc.c;
	//Areas with debris 

	int near1 = 0; //Row
	int near2 = 0; //Column
	int small_dist = ROWS; //Smallest distance between robot and debris
	//Checks array for debris
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLS; y++)
		{
			if ((debris[x][y] == true) && (robot[x][y] == -1)) //If debris is found but no robot in that location
			{
				int tdist = abs(x - row) + abs(y - col);
				if (tdist < small_dist) //Finding smallest distance from robot to debris
				{
					small_dist = tdist;
					near1 = x;
					near2 = y;
				}
			}
		}
	}

	int xdist = abs(row - near1); //Distance in rows
	int ydist = abs(col - near2); //Distance in columns
	int xdiff = row - near1;
	int ydiff = col - near2;

	if (xdist >= ydist)
	{
		if (xdiff < 0) //Debris is below
		{
			if ((robot[row + 1][col] != -1) && (robot[row - 1][col] == -1)) //No robots above but are beneath
			{
				return UP;
			}
			else if ((robot[row + 1][col] != -1) && (robot[row][col - 1] == -1)) //No robots to the left, but are beneath
			{
				return LEFT;
			}
			else
			{
				return DOWN;
			}
		}
		else //Debris is above
		{
			if ((robot[row - 1][col] != -1) && (robot[row + 1][col] == -1)) //No robots below but are above 
			{
				return DOWN;
			}
			else if ((robot[row - 1][col] != -1) && (robot[row][col + 1] == -1)) //No robots to the right, but are above
			{
				return RIGHT;
			}
			else
			{
				return UP;
			}
		}
	}
	else
	{
		if (ydiff < 0) //Debris to the right
		{
			if ((robot[row][col + 1] != -1) && (robot[row][col - 1] == -1)) //No robots to the left, but are right
			{
				return LEFT;
			}
			else if ((robot[row][col + 1] != -1) && (robot[row + 1][col] == -1)) //No robots below, but are right
			{
				return DOWN;
			}
			else
			{
				return RIGHT;
			}
		}
		else //Debris to the left
		{
			if ((robot[row][col - 1] != -1) && (robot[row][col + 1] == -1)) //No robots to the right, but are left
			{
				return RIGHT;
			}
			else if ((robot[row][col - 1] != -1) && (robot[row - 1][col] == -1)) //No robots above, but are left
			{
				return UP;
			}
			else
			{
				return LEFT;
			}
		}
	}
}

void onRobotMalfunction(int id, Loc loc, Area& area, ostream& log)
{
	if (nursebot[id] != -1)
	{
		working[id] = false; //Condition is bad
		log << "Nurse robot " << id << "is damaged." << endl;
		log << "Trying to find a another nurse, please wait." << endl;
		int first_broken = nursebot[id];
		findMyNurse(first_broken, loc, area, log);
		findMyNurse(id, loc, area, log);
	}
	else
	{
		working[id] = false; //Condition is bad
		findMyNurse(id, loc, area, log);
		log << "Robot " << id << "is damaged." << endl;
		log << "Trying to find a nurse, please wait." << endl;
	}
}

void findMyNurse(int id, Loc loc, Area& area, ostream& log)
{
	int row = loc.r; // current row and column
	int col = loc.c;
	int small_dist = ROWS; //Smallest distance between robot and nurse
	int nurseID; //ID of the nurse robot

	if (nursebot[id] != -1)
	{
		nursebot[id] = -1; //The broken robot can't fix any robot
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				int dist = abs(i - row) + abs(j - col); //Dist between robots
				if ((dist < small_dist) && (robot[i][j] != id) && (nursebot[robot[i][j]] == -1) && (working[robot[i][j]] == true))
				{
					nurseID = robot[i][j]; //Nurse has ID at location
					nursebot[nurseID] = id;
				}
			}
		}
		log << "Nurse robot" << nurseID << "is going to repair " << id << endl;
	}
	else
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				int dist = abs(i - row) + abs(j - col); //Dist between robots
				if ((dist < small_dist) && (robot[i][j] != id) && (nursebot[robot[i][j]] == -1))
				{
					nurseID = robot[i][j]; //Nurse has ID at location
					nursebot[nurseID] = id;
				}
			}
		}
		log << "Nurse robot" << nurseID << "is going to repair " << id << endl;
	}
}

Action repairWork(int id, Loc loc, Area& area, ostream& log)
{
	int row = loc.r; // current row and column
	int col = loc.c;

	int malfunctionID = nursebot[id]; //ID of broken robot
	int mal_row = area.locate(malfunctionID).r; //Broken robot row
	int mal_col = area.locate(malfunctionID).c; //Broken robot col

	if (robot[row][col + 1] == malfunctionID) //Broken robot right
	{
		nursebot[id] = -1;
		working[malfunctionID] = true;
		log << "Nurse robot" << id << "is repairing " << malfunctionID << endl;
		return REPAIR_RIGHT;
	}
	else if (robot[row][col - 1] == malfunctionID) //Broken robot left
	{
		nursebot[id] = -1;
		working[malfunctionID] = true;
		log << "Nurse robot" << id << "is repairing " << malfunctionID << endl;
		return REPAIR_LEFT;
	}
	else if (robot[row - 1][col] == malfunctionID) //Broken robot up
	{
		nursebot[id] = -1;
		working[malfunctionID] = true;
		log << "Nurse robot" << id << "is repairing " << malfunctionID << endl;
		return REPAIR_UP;
	}
	else if (robot[row + 1][col] == malfunctionID) //Broken robot down
	{
		nursebot[id] = -1;
		working[malfunctionID] = true;
		log << "Nurse robot" << id << "is repairing " << malfunctionID << endl;
		return REPAIR_DOWN;
	}

	int xdist = abs(row - mal_row); //Distance in rows
	int ydist = abs(col - mal_col); //Distance in columns
	int xdiff = row - mal_row;
	int ydiff = col - mal_col;

	if (xdist >= ydist)
	{
		if (xdiff < 0) //Broken robot is below
		{
			if ((robot[row + 1][col] != -1) && (robot[row - 1][col] == -1) && (robot[row + 1][col] != malfunctionID))
			{
				return UP;
			}
			else if ((robot[row + 1][col] != -1) && (robot[row][col - 1] == -1) && (robot[row + 1][col] != malfunctionID))
			{
				return LEFT;
			}
			else
			{
				return DOWN;
			}
		}
		else //Broken robot is above
		{
			if ((robot[row - 1][col] != -1) && (robot[row + 1][col] == -1) && (robot[row - 1][col] != malfunctionID))
			{
				return DOWN;
			}
			else if ((robot[row - 1][col] != -1) && (robot[row][col + 1] == -1) && (robot[row - 1][col] != malfunctionID))
			{
				return RIGHT;
			}
			else
			{
				return UP;
			}
		}
	}
	else
	{
		if (ydiff < 0) //Broken to the right
		{
			if ((robot[row][col + 1] != -1) && (robot[row][col - 1] == -1) && (robot[row][col + 1] != malfunctionID))
			{
				return LEFT;
			}
			else if ((robot[row][col + 1] != -1) && (robot[row + 1][col] == -1) && (robot[row][col + 1] != malfunctionID))
			{
				return DOWN;
			}
			else
			{
				return RIGHT;
			}
		}
		else //Broken robot to the left
		{
			if ((robot[row][col - 1] != -1) && (robot[row][col + 1] == -1) && (robot[row][col - 1] != malfunctionID))
			{
				return RIGHT;
			}
			else if ((robot[row][col - 1] != -1) && (robot[row - 1][col] == -1) && (robot[row][col - 1] != malfunctionID))
			{
				return UP;
			}
			else
			{
				return LEFT;
			}
		}
	}
}

void onClockTick(int time, ostream& log) {
	if (time % 100 == 0) log << time << " ";
}


