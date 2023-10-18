//Mohamed Amine Saoud
//CS181


#include <iostream>
using namespace std;
#include <string>
#include "Manager.h"
#include <iomanip>
int main()
{
	//declaring variables for the user input and for the Manager array
	//constructor
	//declaring the maxPay for the maximum payment
	// and the avgPay for the average payment

	double theWage = 0, theHours = 0, theBonus = 0,avgPay=0,maxPay=0;
	string theName = "";
	int sizeOfArray = 0,index=0;
	do//do while loop prevents the user from enetering
		//more than 100 manager
	{
		cout << "Enter number of managers: " << endl;
		cin >> sizeOfArray;
	} while (sizeOfArray>=100);
	//array of managers(pointers)
	Manager* arrayOfManagers = new Manager[sizeOfArray];
	//getting the input and filling the manager array
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << "Enter manager "<<i<<" name:" << endl;
		cin.ignore();
		getline(cin, theName,'\n');
		cout << "Enter manager " << i << " hourly wage:" << endl;
		cin >> theWage;

		cout << "Enter manager " << i << " hours worked:" << endl;
		cin >> theHours;
		cout << "Enter manager " << i << " bonus:" << endl;
		cin >> theBonus;
		Manager tempManager (theName,theWage,theHours,theBonus);
		arrayOfManagers[i] = tempManager;
	}
	//looping through the array to find the maximum payment
	// and to calculate the averge payment
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (maxPay < arrayOfManagers[i].calcPay())
		{
			maxPay = arrayOfManagers[i].calcPay();
			index = i;
		}
    	avgPay += arrayOfManagers[i].calcPay();
	}
	//dividing by the size to get the average payment
	avgPay /= sizeOfArray;
	//displaying the result and making sure all dollar amounts
	// correct to 2 decimal places ,using fixed to fix the number
	// of decision with setprecision.

	cout <<"Highest paid manager is "<<arrayOfManagers[index].getName()<<" who is paid $" << fixed << setprecision(2) <<maxPay<< endl;
	cout << "Average pay is $" << fixed << setprecision(2) <<  avgPay << endl;
}
