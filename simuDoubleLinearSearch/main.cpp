#include <iostream>
#include <cstdlib>//library to use the rand function
#include <vector>

using namespace std;
vector<int> simuLinearSearch(const vector<int>& array, int& searchValue,int& steps)
{
	steps = 0;//to count the number of steps to find both values per iteration
	vector<int> searchResult;//the new array to return if the search
	// successful otherwise this will be an empty vector!
	int count =0;//used to manipulate the lineat searching
	for (int i = 0; i < array.size(); i++)//main loop to search for values
	{
		steps++;
		if (searchValue == array.at(i))
		{
			count++;
			searchResult.push_back(i);//add the index for the value found to
			//the returned array
		}
		if (count == 2)//if it is true we found both values
		{
			break;//no need to search more
		}
	}
	if (count != 2)
	{
		searchValue = -1;//value is not found on this case
	}
	return searchResult;//return the array that holds the two index values
}
vector<int> setArray(int N)//set the array for the simulation
{
	vector<int> array;
	int randomValue = -1,i=0; //randomly give a value that is constricted
	//between 0 and 15000
	while(i<N)
	{
		randomValue = rand();
		while (randomValue<0 || randomValue>15000)
		{
			randomValue = rand();
		}
		array.push_back(randomValue);// fill the array
		i++;
	}
	return array;
}

int main()
{
int Size=0;
 cout<<"Size of the array ? "<<endl;
  cin>>Size;
	int searchValue=0;
	vector<int> array=setArray(100000);
	vector<int> searchResult;
	int steps=0;
	int minSteps=1000000,maxSteps=-1,avgSteps=0;// the minSteps is initialized in a way that
	//allows the minSteps change from the first iteration same thing for maxSteps
	int Hits=0;
	int Misses=0;
	for (int j = 1; j < 10001; j++)
	{
		searchValue = rand();
		while (searchValue < 0 || searchValue>15000)
		{
			searchValue = rand();
		}
		searchResult = simuLinearSearch(array, searchValue, steps);
		if (maxSteps < steps)
		{
			maxSteps = steps;
		}
		if (minSteps > steps)
		{
			minSteps = steps;
		}
		if(searchValue==-1)
		{
			Misses++;
		}
		else
		{
			Hits++;
		}
		avgSteps += steps;

	}
	//final display
	cout << "\n *** *** *** *** *** *** \n";

	cout << "Results :\n" << " misses = " << Misses << "\n hits= " <<
		Hits <<"\n Min steps ="<<minSteps << "\n Max steps ="
		<< maxSteps << "\n average steps =" << avgSteps/1000 <<endl;
     return 0;
}
