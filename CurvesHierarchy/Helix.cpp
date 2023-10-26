#include "Helix.h"

Helix::Helix(double x, double y, double radius, double step)
{
	x0 = x;
	y0 = y;
	z0 = 0;
	this->radius = radius;
	this->step = step;
}

Helix::~Helix()
{

}

array<double, 3> Helix::point(double t)
{
	array<double, 3> coords;
	coords[0] = x0 + radius * cos(t);
	coords[1] = y0 + radius * sin(t);
	coords[2] = z0 + (t * step) / (2 * M_PI);
	return coords;
}

array<double, 3> Helix::derivative(double t)
{ 
	array<double, 3> coords;
	coords[0] = radius * (-sin(t));
	coords[1] = radius * cos(t);
	coords[2] = step / (2 * M_PI);
	return coords;
}

double Helix::getRadius() { return radius; }