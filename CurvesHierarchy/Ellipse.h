#include "Curve.h"

class Ellipse : public Curve
{
private:
	double radius_y;
public:
	Ellipse(double x, double y, double x_radius, double y_radius);
	virtual ~Ellipse();
	virtual array<double, 3> point(double t) override;
	virtual array<double, 3> derivative(double t) override;
	virtual double getRadius() override;
};