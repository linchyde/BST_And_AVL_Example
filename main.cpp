#include <iostream>
#include <string>
#include <list>
#include <chrono>
#include "BST.h"
#include "AVL.h"
#include "IntegerNode.h"
#include <random>

using namespace std;
using namespace std::chrono;

//function sourced from https://www.geeksforgeeks.org/list-cpp-stl/
void showlist(list <int> g)
{
	list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

int menuSelect()
{
	int choice;
	cout << "Please Select an Option: " << "\n" << endl;
	cout << "1 - Search for a number between 1-10000 in all data structures" << "\n" << endl;
	cout << "2 - EXIT " << "\n" << endl;
	cin >> choice;	
	return choice;	
}



void main()
{
	list <int> numbers;
	BST numbers1;
	AVL numbers2;
	
	//create the lists of random numbers (rand not seeded so same numbers for each list)
	for (int r = rand()% 10000 + 1; r < 10000; r++) //used 10k to save on wait time
	{
		
		numbers.push_back(r);
		numbers1.insert(new IntegerNode(r));
		numbers2.insert(new IntegerNode(r));
		
	}

	

	int choice = menuSelect();
	//time code help from - https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
	if (choice == 1)
	{
		int selection;
		cout << "Enter your selection " << endl;
		cin >> selection;
		//start time for numbers search
		auto start = high_resolution_clock::now();
		//create iterator for and search list
		std::list<std::int32_t>::iterator it1;
		it1 = std::find(numbers.begin(), numbers.end(), selection);
		if (it1 != numbers.end())
		{
			cout << selection << " Is found in the LIST " << endl;
		}
		else
		{
			cout << selection << " IS not in the list " << endl;
		}
		//stop time for numbers search
		auto stop = high_resolution_clock::now();
		//measure time taken for numbers to complete search
		auto duration1 = duration_cast<microseconds>(stop - start);
		cout << "Search time for standard list search was: " << duration1.count() << " microseconds" << endl;

		//search BST
		auto start1 = high_resolution_clock::now();
		IntegerNode* Sptr = numbers1.search(selection, true);

		if (Sptr == NULL)
			cout << "Cannot find that integer" << endl;
		else
			cout << " Found " << Sptr->numberNode << " With matching ID in BST " << endl;
		auto stop1 = high_resolution_clock::now();
		auto duration2 = duration_cast<microseconds>(stop1 - start1);
		cout << "Search time for standard BST search was: " << duration2.count() << " microseconds" << endl;

		//serch AVL
		auto start2 = high_resolution_clock::now();
		IntegerNode* Sptr2 = numbers2.search(selection, true);

		if (Sptr2 == NULL)
			cout << "Cannot find that integer" << endl;
		else
			cout << " Found " << Sptr2->numberNode << " With matching ID in AVL" << endl;

		if (selection == NULL)
			cout << "Selected number was not found in any structure " << endl;
		auto stop2 = high_resolution_clock::now();
		auto duration3 = duration_cast<microseconds>(stop2 - start2);
		cout << "Search time for standard AVL search was: " << duration3.count() << " microseconds" << endl;
		
	}
		if (choice == 2)
		return;


	system("pause");
}