#include <iostream>
#include <typeinfo>
#include <cmath>
#include "Header.h"
using namespace std;

template <class T, int n>
void Point<T, n>::setPoint(T coordinates[]) //setter
{
	for (int i = 0; i < n; i++)
	{
		this->point[i] = coordinates[i];
	}
}

template <class T, int n>
Point<T, n>::Point(T coordinates[n]) //constructor
{
	cout << "Declaring " << typeid(T).name() << ", " << n << "D point ";
	this->setPoint(coordinates);
	cout << "(";
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			cout << getCoordinate(i) << ")" << endl;
		}
		else
		{
			cout << getCoordinate(i) << ",";
		}
	}
}

template <class T, int n> //getter
T Point<T, n> ::getCoordinate(int k)
{
	return this->point[k];
}

template <class T, int n> //destructor
Point<T,n>::~Point()
{
}


template <class T, int n>
void Distance(Point<T,n> a, Point<T,n> b) //distance function
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += pow(b.getCoordinate(i) - a.getCoordinate(i), 2);
	}
	sum = sqrt(sum);
	cout << "The distance between the two points is " << sum << endl;
}
int main()
{
	double pointOne[3] = { 3.0,2.0,1.0 };
	double pointTwo[3] = { 5.0,6.0,7.0 };
	Point<double, 3> a(pointOne);
	Point<double, 3> b(pointTwo);
	Distance(a, b);
	int pointThree[2] = { 10, 8 };
	int pointFour[2] = { 5, 9 };
	Point<int, 2> c(pointThree);
	Point<int, 2> d(pointFour);
	Distance(c, d);
	return 0;
}