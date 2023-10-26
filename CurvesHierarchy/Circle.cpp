#include "Circle.h"

Circle::Circle(double x, double y, double radius)
{
	x0 = x;
	y0 = y;
	z0 = 0;
	this->radius = radius;
}

Circle::~Circle()
{

}

array<double, 3> Circle::point(double t)
{
	array<double, 3> coords;
	coords[0] = x0 + radius * cos(t);
	coords[1] = y0 + radius * sin(t);
	coords[2] = z0;
	return coords;
}

array<double, 3> Circle::derivative(double t)
{ 
	array<double, 3> coords;
	coords[0] = radius * (-sin(t));
	coords[1] = radius * cos(t);
	coords[2] = 0;
	return coords;
}

double Circle::getRadius() { return radius; }