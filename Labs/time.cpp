/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 10 - Task E

This program adds a new function: bool timeOverlap(TimeSlot ts1, TimeSlot ts2); the function should return true 
if the two time slots overlap, otherwise return false. (Take into account the starting times of the time slots 
and the duration of the scheduled movies.)
*/

#include <iostream>
using namespace std;

class Time {
public:
    int h;
    int m;
};

//Given
enum Genre { ACTION, COMEDY, DRAMA, ROMANCE, THRILLER };

//Given
class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

//Given
class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

//Given
void printMovie(Movie mv) {
    string g;
    switch (mv.genre) {
    case ACTION: g = "ACTION"; break;
    case COMEDY: g = "COMEDY"; break;
    case DRAMA: g = "DRAMA";  break;
    case ROMANCE: g = "ROMANCE"; break;
    case THRILLER: g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//Task B - create and return a new moment of time that is min minutes after time0
Time addMinutes(Time time0, int min)
{
    int hours, mins = 0;
    hours = min / 60; //Amount of hours equivalent to the elasped time
    mins = min % 60; //Remainder mins after corresponding hours
    time0.h += hours;
    if (time0.m + mins > 59) //If the resulting minutes exceeded 59, will start the next hour
    {
        time0.h += 1; 
        time0.m += mins - 60;
    }
    else
    {
        time0.m += mins;
    }
    return time0;
}

//Task C - hich will print time slots using the given functionand classes: Movie, TimeSlot, and printMovie(Movie m)
void printTimeSlot(TimeSlot ts)
{
    Time ending = addMinutes(ts.startTime, ts.movie.duration); //Creates ending time after given start time and duration
    printMovie(ts.movie);
    cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << ending.h << ":" << ending.m << "]" << endl;
}

//Task D - function should produce and return a new TimeSlot for the movie nextMovie, scheduled immediately after the time slot ts
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time ending = addMinutes(ts.startTime, ts.movie.duration); 
    TimeSlot after = { nextMovie, ending };
    return after;
}

//Task A - return the number of minutes from 0:00AM until time
int minutesSinceMidnight(Time time)
{
    int mins = 0;
    Time midnight = { 0, 0 }; //Midnight 12:00 AM --> 0:00 24/hr format
    mins = (time.h - midnight.h) * 60; //60 mins per hr
    mins += (time.m - midnight.m); //Add remaining mins elasped
    return mins;
}

//receive two Time arguments earlier and later and report how many minutes separate the two moments
int minutesUntil(Time earlier, Time later)
{
    int mins = 0;
    mins = (later.h - earlier.h) * 60; //60 mins per hr
    mins += (later.m - earlier.m); //Add remaining mins elasped
    return mins;
}

//Task E - should return true if the two time slots overlap, otherwise return false.
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int diff1 = minutesUntil(ts1.startTime, ts2.startTime); //ts1 - ealrier, ts2 - later
    int diff2 = minutesUntil(ts2.startTime, ts1.startTime); //ts2 - ealrier, ts1 - later
    if (diff1 >= 0 && ts1.movie.duration > diff1) //If ts1 runs longer than ts2's start time
    {
        return true;
    }
    else if (diff2 >= 0 && ts2.movie.duration > diff2) //If ts2 runs longer than ts1's start time
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Movie movie1 = { "Back to the Future", COMEDY, 116 };
    Movie movie2 = { "Black Panther", ACTION, 134 };
    Movie movie3 = { "Knives Out", DRAMA, 131 };
    Movie movie4 = { "My Hero Academia: Hero's Rising", ACTION, 104 };

    TimeSlot morning = { movie1, {9, 15} };
    TimeSlot daytime = { movie2, {12, 15} };
    TimeSlot evening = { movie2, {16, 45} };
    TimeSlot knives = { movie3, {2, 45} };
    TimeSlot hero = { movie4, {12, 10} };
    
    printTimeSlot(knives);
    printTimeSlot(scheduleAfter(knives, movie4));
}