/*#include "Sphere.h"*/
#include "GeometricObject.h"

GeometricObject::GeometricObject(void)
{
}

bool GeometricObject::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
	return false;
}
