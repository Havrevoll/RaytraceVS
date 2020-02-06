#pragma once
#include "Utilities/Ray.h"
#include "Utilities/RGBColor.h"
#include "Shaderec.h"


class GeometricObject
{
public:

// skal det inn ein konstruktor her eller?

	virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;

protected:
	RGBColor color;

};

