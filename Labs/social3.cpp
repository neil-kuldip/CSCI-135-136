/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 11 - Task C

This program is about creating a social network with object-oriented programming.
It is an improved version of the previous program. The class Network should be changed to keep the friendship 
(following) relation between the users.
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
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];

    // friendship matrix:
    // following[id1][id2] == true when id1 is following id2
    bool following[MAX_USERS][MAX_USERS];    // new 

    int findID(string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);

    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2); // new

    // Print Dot file (graphical representation of the network)
    void printDot();                         // new
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
    for (int i = 0; i < MAX_USERS; i++) //Set each term in the friendship matrix to false
    {
        for (int j = 0; j < MAX_USERS; j++)
        {
            following[i][j] = false;
        }
    }
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

bool Network::follow(string usrn1, string usrn2)
{
    int element1 = findID(usrn1); //Element in profiles array is the same row & column in friendship matrix 
    int element2 = findID(usrn2);
    if ((element1 == -1) || (element2 == -1)) //If the usernames are not found in profile array
    {
        return false;
    }

    following[element1][element2] = true;
    return true;
}

void Network::printDot()
{
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++) //Iterating in users through profiles array
    {
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    }

    //Network following
    for (int i = 0; i < numUsers; i++) //Matrix requires nested loop
    {
        for (int j = 0; j < numUsers; j++)
        {
            if (following[i][j] == true)
            {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main() 
{
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for (int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}