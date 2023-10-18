#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "Employee.h"
//create the class Manager
class Manager :public Employee //inherit publicly the Employee Class
{
private:
	double Bonus;
public:
	//creating a default constructor
	Manager();
	//creating the paramaretized construcor
	Manager(string theName, double theWage, double theHours, double theBonus);
	double calcPay();

};


#endif // MANAGER_H_INCLUDED
