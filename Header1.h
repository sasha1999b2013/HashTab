#pragma once
#ifndef  POINT_H 
#define  POINT_H
#include<iostream>
using namespace std;
struct TPoint
{
	int x;
	int y;
public:
	friend std::ostream& operator<< (std::ostream &out, const TPoint &point)
	{
		out << "Точка(" << point.x << ", " << point.y << ")";
		return out;
	}
	bool operator == (TPoint &point)
	{
		return (x == point.x) && (y == point.y);
	}
	bool operator != (TPoint &point)
	{
		return (x != point.x) || (y != point.y);
	}
	friend std::istream& operator>>(istream& in, TPoint &point)
	{
		cout << "введите координату х: ";
		in >> point.x;
		cout << "введите координату у: ";
		in >> point.y;
		return in;
	}
};
#endif