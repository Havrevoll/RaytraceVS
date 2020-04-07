#pragma once

#include "Utilities/Constants.h"
#include "Utilities/Ray.h"
#include "Utilities/RGBColor.h"

class World;

class Tracer
{
public:
	Tracer(void);

	Tracer(World* w_ptr);

	virtual RGBColor 
		trace_ray(const Ray& ray, const int depth) const;

protected:

	World* world_ptr;
};

