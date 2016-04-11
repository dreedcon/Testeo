#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

#pragma once
template<class data>
class Point2D{

public:

	data x;
	data y;

public:

	Point2D(){ x = 0; y = 0; }
	Point2D(data _x, data _y){ x = _x; y = _y; };

	Point2D operator+ (const Point2D& a)const
	{
		Point2D tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}

	Point2D operator- (const Point2D& a)const
	{
		Point2D tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}

	//recuerda: el += no es constante porque va incrementando
	Point2D operator+= (const Point2D& a)
	{
		x += a.x;
		y += a.y;
		return(*this);
		//*this:regresas un puntero que apunta a el objeto
	}
	//recuerda: el += no es constante porque va decrementando
	Point2D operator-= (const Point2D& a)
	{
		x -= a.x;
		y -= a.y;
		return(*this);
		//*this:regresas un puntero que apunta a el objeto
	}

	Point2D operator= (const Point2D& a)
	{
		x = a.x;
		y = a.y;
		return(*this);
	}

	bool operator== (const Point2D& a)const
	{
		if (x == a.x && y == a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!= (const Point2D& a)const
	{
		if (x != a.x || y != a.y)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool isZero()const
	{
		if (x == 0 && y == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SetZero()
	{
		x = 0;
		y = 0;
	}

	//what we do here is to calculate the distance between two points use Pitagoras
	float DistanceTo(const Point2D p)const
	{
		float Distance1;
		Distance1 = sqrt((x - p.x)*(x - p.x)) + ((y - p.y)*(y - p.y));
		return Distance1;
	}
};
