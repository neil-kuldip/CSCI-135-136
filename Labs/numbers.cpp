/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 5 - Task G

This program adds a function ---> int largestTwinPrime(int a, int b);
that returns the largest twin prime in the range a ≤ N ≤ b.
If there is no twin primes in range, then return -1.
*/

#include <iostream>
using namespace std;

//Task A -> Checking if inputted numbers are divisible evenly
bool isDivisibleBy(int n, int d) 
{
	if (d == 0)
	{
		return false; 
	}
	else if (n % d == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Task B -> Checking if the inputed number is prime
bool isPrime(int n)
{
	int num = 0;
	for (int compare = 2; compare < n; compare++) //Prime numbers are not divisible by any number above 2
	{
		if (n % compare == 0)
		{
			num++;
		}
	}
	if (n < 2) //Prime numbers are not smaller than 2
	{
		return false;
	}
	else if (num > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Task C -> Determining the next smallest prime number 
int nextPrime(int n)
{
	n++;
	while (!isPrime(n)) //Uses the prime determining function
	{
		n++;
	}
	return n; //Returns the next smallest prime number
}

//Task D -> Counts the total number of prime numbers in a decided interval
int countPrimes(int a, int b)
{
	int counter = 0; //Counting number of prime numbers
	for (int i = a; a <= b; a++)
	{
		if (isPrime(a)) //Uses prime determine function 
		{
			counter++; //Increments prime number counter
		}
	}
	return counter;
}

//Task E -> Determines if the inputted number is a twin prime (either #-2 or #+2 (or both of them) is also a prime)
bool isTwinPrime(int n)
{
	int cond1 = n - 2; //N-2 must be prime
	int cond2 = n + 2; //N+2 must be prime
	if (isPrime(n) && (isPrime(cond1) || isPrime(cond2))) //Uses prime determe to test conditions
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Task F -> Determines the next twin prime number after the user's number
int nextTwinPrime(int n)
{
	n++;
	while (!isTwinPrime(n))
	{
		n++; //Increments the value of n until it's twin prime
	}
	return n; //Returns the next twin prime number
}

//Task G -> Finds the largest twin prime number in a desired interval
int largestTwinPrime(int a, int b)
{
	int largest = -1; //The largest twin prime number
	for (int i = b; i >= a; i--)
	{
		if (isTwinPrime(i))
		{
			largest = i;
			break;

		}
	}
	return largest;
}

int main()
{
	int begin = 0; 
	cout << "Enter a number: "; //Asks user for input
	cin >> begin;

	int end = 0;
	cout << "Enter a number: "; //Asks user for input
	cin >> end;

	int largest_twin = largestTwinPrime(begin, end);
	cout << largest_twin << endl;
	
	return 0;
}