#pragma once
#include "GeometricObject.h"
class Sphere :
	public GeometricObject
{
public:
	Sphere(void);

	Sphere(const Point3D c, const double& r);

	virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;

private:

	Point3D center; // Point of center of sphere

	float radius; // radius of the sphere
	static const double kEpsilon; // see chapter 16
};

