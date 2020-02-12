#include "SingleSphere.h"

SingleSphere::SingleSphere(void) : Tracer()
{
}

SingleSphere::SingleSphere(World* _worldPtr) : Tracer(_worldPtr)
{
}

RGBColor SingleSphere::trace_ray(const Ray& ray) const
{
	return RGBColor();
}