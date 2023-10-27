#ifndef HELIX_H
#define HELIX_H

#include "MyDLL.h"
#include "Curve.h"

class MYDLL_API Helix : public Curve
{
private:
	double step;
public:
	Helix(double x, double y, double radius, double step);
	virtual ~Helix();
	virtual array<double, 3> point(double t) override;
	virtual array<double, 3> derivative(double t) override;
	virtual double getRadius() override;
};

#endif // !HELIX_H