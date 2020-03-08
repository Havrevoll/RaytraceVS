#pragma once
#include "Utilities/Ray.h"
#include "Utilities/RGBColor.h"
#include "Shaderec.h"


class GeometricObject
{
public:

// skal det inn ein konstruktor her eller?
	GeometricObject(void);

	virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;

	void set_color(const float r, const float g, const float b);
	RGBColor get_color();

protected:
	RGBColor color;

};

inline void GeometricObject::set_color(const float r, const float g, const float b)
{
	color = RGBColor(r, g, b);
}

inline RGBColor GeometricObject::get_color()
{
	return color;
}
