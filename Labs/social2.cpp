/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 11 - Task B

This program is about creating a social network with object-oriented programming.
It implements the first version of the class Network, whose functionalities are:
    1) adding new users to the network, 
    2) following, and 
    3) posting messages. 
We are going to develop them in these three tasks.
*/

#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname = "";
}

string Profile::getUsername()
{
    return username;
}

string Profile::getFullName()
{
    string Fullname = displayname + " (@" + username + ")";
    return Fullname;
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                     // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID(string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
};

int Network::findID(string usrn)
{
    for (int i = 0; i < numUsers; i++) //Current end of the profiles array defined by numUsers
    {
        if (profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }
    return -1; //User is not found in profile
}

Network::Network()
{
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn)
{
    if ((numUsers == MAX_USERS) || (usrn.length() == 0)) //New username usrn must be a non-empty string and the array profiles is not full
    {
        return false;
    }
    for (int j = 0; j < usrn.length(); j++) ////New username usrn must be a alphanumeric string 
    {
        if ((!isalpha(usrn[j]) && (!isdigit(usrn[j]))))
        {
            return false;
        }
    }
    for (int k = 0; k <= numUsers; k++)
    {
        if (profiles[k].getUsername() == usrn) //Checks if is no other users in the network with the same username
        {
            return false;
        }
    }

    Profile p(usrn, dspn); //Constructed a new profile p
    profiles[numUsers] = p; //Added p to the profiles array in the first empty element
    numUsers++; //Increment the known filled array counter
    return true; //Return true for that the user was added
}

int main() 
{
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for (int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
            "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}