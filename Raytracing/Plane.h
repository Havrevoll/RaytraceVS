#pragma once
#include "GeometricObject.h"
class Plane :
	public GeometricObject
{
public:
	Plane(void);

	Plane(const Point3D p, const Normal& n);


	virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;

private:

	Point3D point; // Point through which plane passes

	Normal normal; // normal to the plane
	static const double kEpsilon; // see chapter 16

	/*RGBColor color;*/

};

