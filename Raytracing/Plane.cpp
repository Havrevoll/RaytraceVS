#include "Plane.h"


const double Plane::kEpsilon = 0.001;

Plane::Plane(void)
{
}

Plane::Plane(const Point3D p, const Normal& n) : normal(n), point(p)
{

}

bool Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
	double t = (point - ray.o) * normal / (ray.d * normal);

	if (t > kEpsilon) {
		tmin = t;
		sr.normal = normal;
		sr.local_hit_point = ray.o + t * ray.d;

		return (true);
	}
	else {
		return (false);
	}
}