#pragma once
#include "Tracer.h"
class MultipleObjects :
	public Tracer
{
public:
	MultipleObjects(void);
	MultipleObjects(World* _worldPtr);

	virtual RGBColor trace_ray(const Ray& ray) const;
};

