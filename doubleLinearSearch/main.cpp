#include <iostream>
#include <vector>

using namespace std;
vector<int> LinearSearch(const vector<int>& array,int& searchValue)
{ 	vector<int> searchResult;//the new array to return if the search
 // successful otherwise this will be an empty vector!
	int count = 0;
	for (int i = 0; i < array.size(); i++)
	{

	    if(searchValue==array.at(i))
		{
			count++;
			searchResult.push_back(i);
		}
		if (count == 2)
		{
			break;
		}
	}
	if (count != 2)
	{
		searchValue = -1;
	}
	return searchResult;
}

int main()
{
	int searchValue = 16;
	vector<int> array {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};


	vector<int> searchResult;
	/*vector<int> array {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};
	int searchValue= 10;*/

	searchResult =LinearSearch(array,searchValue);
	if (searchValue == -1)
		cout << "The search value was not found !" << endl;
	else
	{
		cout << "\n";
		cout << "\t \tDisplaying the array holding the indexes of both found values :"
			<< endl;
		for (int i = 0; i < searchResult.size(); i++)
		{
			cout << "\t \tvalue found at index number :" << searchResult[i] << endl;

		}
	}


    cin.get();
	return 0;
}
