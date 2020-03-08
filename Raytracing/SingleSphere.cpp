#include "SingleSphere.h"
#include "World.h"
#include "Shaderec.h"

SingleSphere::SingleSphere(void) : Tracer()
{
}

SingleSphere::SingleSphere(World* _worldPtr) : Tracer(_worldPtr)
{
}

RGBColor SingleSphere::trace_ray(const Ray& ray) const
{
	ShadeRec sr(*world_ptr); // not used
	double t; // not used

	/*if (world_ptr->sphere.hit(ray, t, sr))
		return (red);
	else */
		return (black);
}