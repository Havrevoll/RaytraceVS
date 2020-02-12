#pragma once
#include "GeometricObject.h"


class Sphere :
	public GeometricObject
{
public:
	Sphere(void);

	Sphere(const Point3D c, const double& r);

	virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;

	void set_center(const Point3D& c);

	void set_center(const double x, const double y, const double z);

	void set_radius(const double r);

private:

	Point3D center; // Point of center of sphere

	float radius; // radius of the sphere
	static const double kEpsilon; // see chapter 16
};

inline void Sphere::set_center(const Point3D& c)
{
	center = c;
}

inline void Sphere::set_center(const double x, const double y, const double z)
{
	center.x = x;
	center.y = y;
	center.z = z;

}

 inline void Sphere::set_radius(const double r)
{
	 radius = r;
}