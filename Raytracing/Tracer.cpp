#include "Tracer.h"
#include <cstddef>

Tracer::Tracer(void) : world_ptr(NULL)
{
}

Tracer::Tracer(World* w_ptr) : world_ptr(w_ptr)
{
}

RGBColor Tracer::trace_ray(const Ray& ray) const
{
	return (black);
}


