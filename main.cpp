// CS 575 Assignment 1.cpp : This file contains code that takes the difference of of all keys in an array of 
// values and then returns the first key it finds from the original array that matches a difference in the array
// of differences.

#include <iostream>
#include <vector>
#include <fstream>
using namespace std; 

int difference(int x, int y);

int main()
{
	string inputFile;
	cout << "Please type in the address of your input file: ";
	cin >> inputFile;
	ifstream data(inputFile);
	if (data.fail())
	{
		cerr << "File could not be opened.";
		exit(1);
	}
	vector<int> numbers, differences;
	while (!data.eof())
	{
		int number;
		data >> number;
		numbers.push_back(number);
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i; j < numbers.size(); j++)
		{
			if (j == i and (i != numbers.size()-1))
				j = i + 1;
			else if (j == i and i == numbers.size() - 1)
				break;
			differences.push_back(difference(numbers[i], numbers[j]));
		}
	}
	ofstream output("output.txt");
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < differences.size(); j++)
		{
			// if we have a match, write that match to a file and exit the program
			if (numbers[i] == differences[j])
			{
				output << numbers[i] << "\n";
				exit(0);
			}
			// else output nothing
			else
				output << "";
		}
	}
	return 0;
}

int difference(int x, int y)
{
	return abs(x - y);
}