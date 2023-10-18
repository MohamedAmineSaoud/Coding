#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Employee
{
protected:
	string name;
	double wage;
	double hours;
public:
	// Create a new employee
	Employee(string theName, double theWage, double theHours);
	// Calculate the employee’s pay.
	double calcPay() const;
	string getName() const;
};


#endif // EMPLOYEE_H_INCLUDED
