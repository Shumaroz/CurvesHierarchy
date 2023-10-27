#ifndef CRICLE_H
#define CRICLE_H

#include "MyDLL.h"
#include "Curve.h"

class MYDLL_API Circle : public Curve
{
private:

public:
	Circle(double x, double y, double radius);
	virtual ~Circle();
	virtual array<double, 3> point(double t) override;
	virtual array<double, 3> derivative(double t) override;
	virtual double getRadius() override;
};

#endif // !CRICLE_H