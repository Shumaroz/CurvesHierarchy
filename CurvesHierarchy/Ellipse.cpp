#include "Ellipse.h"

Ellipse::Ellipse(double x, double y, double radius_x, double radius_y)
{
	x0 = x;
	y0 = y;
	z0 = 0;
	this->radius = radius_x;
	this->radius_y = radius_y;
}

Ellipse::~Ellipse()
{

}

array<double, 3> Ellipse::point(double t)
{
	array<double, 3> coords;
	coords[0] = x0 + radius * cos(t);
	coords[1] = y0 + radius_y * sin(t);
	coords[2] = z0;
	return coords;
}

array<double, 3> Ellipse::derivative(double t)
{
	array<double, 3> coords;
	coords[0] = radius * (-sin(t));
	coords[1] = radius_y * cos(t);
	coords[2] = 0;
	return coords;
}

double Ellipse::getRadius() { return radius; }