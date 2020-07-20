#pragma once
#ifndef HEADER_H
#define HEADER_H

template <class T, int n>
class Point
{
private:
	T point[n]; 
	int dimension;
public:
	Point(T coordinates[n]); //constructor
	~Point();    //destructor
	T getCoordinate(int k); //getter	
	void setPoint(T coordinates []); //setter
};

template <class T, int n>
void Distance(Point<T, n> a, Point<T, n> b); //distance function

#endif