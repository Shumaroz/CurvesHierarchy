#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <array>
#include <iomanip>

using namespace std;

class Curve
{
protected:
	double radius;
	double x0, y0, z0;
public:
	virtual array<double, 3> point(double t) = 0;
	virtual array<double, 3> derivative(double t) = 0;
	virtual double getRadius() = 0;
};