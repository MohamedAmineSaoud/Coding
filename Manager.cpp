#include "Manager.h"
//definition the paramaretized construcor
Manager::Manager(string theName, double theWage, double theHours, double theBonus)
	:Employee(theName,theWage,theHours)
{
	this->Bonus = theBonus;
}
//redefining the calcPay method
double Manager::calcPay()
{
	return hours * wage + Bonus;
}
//definition of the default constructor
Manager::Manager()
	:Employee("", 0, 0)
{
	Bonus = 0;
}
