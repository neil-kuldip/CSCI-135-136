/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 11 - Task D

This program is about creating a social network with object-oriented programming.
It is an improved version of the previous program. The class Network should be changed to allow users post messages and remember them.
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

struct Post {
    string username;
    string message;
};

class Network {
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];
    static const int MAX_POSTS = 100;         // new --> maximum number of posts allowed in array
    int numPosts;                             // new --> number of posts
    Post posts[MAX_POSTS];                    // new --> array of all posts
    int findID(string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();

    // Add a new post
    bool writePost(string usrn, string msg);  // new

    // Print user's "timeline"
    bool printTimeline(string usrn);          // new
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
    numPosts = 0;
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

bool Network::writePost(string usrn, string msg)
{
    int valid_user = findID(usrn);
    if ((numPosts == MAX_POSTS) || (valid_user == -1))
    {
        return false;
    }
    //if the username is found in the network and the posts array is not full
    posts[numPosts] = { usrn, msg }; //Array gets existing user's new post
    numPosts++; //Updates numPosts to the next empty element
    return true;
}

bool Network::printTimeline(string usrn)
{
    for (int i = numPosts; i >= 0; i--)
    {
        string check_follow = posts[i].username;
        int element1 = findID(usrn); //Elements in friendship matrix
        int element2 = findID(check_follow);
        if ((check_follow == usrn) || (following[element1][element2] == true))
        {
            string fullname = profiles[element2].getFullName();
            cout << fullname << ": " << posts[i].message << endl;
        }
    }
    return true;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
}
