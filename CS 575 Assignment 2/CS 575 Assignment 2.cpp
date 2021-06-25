// CS 575 Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
using namespace std;

class Point
{
public:
	int x, y;
};

int sortX(const void* a, const void* b)
{
	Point* p1 = (Point*)a, * p2 = (Point*)b;
	return (p1->x - p2->x);
}

int sortY(const void* a, const void* b)
{
	Point* p1 = (Point*)a, * p2 = (Point*)b;
	return (p1->y - p2->y);
}

float distance(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y)
	);
}

float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (distance(P[i], P[j]) < min)
				min = distance(P[i], P[j]);
	return min;
}

float min(float x, float y)
{
	return (x < y) ? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
	float min = d; 
	qsort(strip, size, sizeof(Point), sortY);
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (distance(strip[i], strip[j]) < min)
				min = distance(strip[i], strip[j]);

	return min;
}

float closestUtil(Point P[], int n)
{
	if (n <= 3)
		return bruteForce(P, n);

	int mid = n / 2;
	Point midPoint = P[mid];

	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);

	float d = min(dl, dr);

	Point* strip = new Point[10000];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;
	return min(d, stripClosest(strip, j, d));
}
float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), sortX);
	return closestUtil(P, n);
}

int main()
{
	// read in the input data
	string inputdoc;
	cout << "Enter the path for your input file: ";
	cin >> inputdoc;
	ifstream input(inputdoc);
	Point P[10000];
	int x, y;
	for (int i = 0; i < 10000; i++)
	{
		input >> x >> y;
		P[i].x = x;
		P[i].y = y;
	}
	int n = sizeof(P) / sizeof(P[0]);
	ofstream output("ouput.txt");
	output << closest(P, n);
	return 0;
}
