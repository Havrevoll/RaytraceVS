
#include "World.h"
#include "Utilities/Constants.h"

// geometric objects

#include "Sphere.h"

// Tracers

#include "SingleSphere.h"

// Utilities

#include "Utilities/Vector3D.h"
#include "Utilities/Point3D.h"
#include "Utilities/Normal.h"
#include "Shaderec.h"
#include "Utilities/Ray.h"
#include "Utilities/Maths.h"




// build functions
#include "BuildRedSphere.cpp" // builds the red sphere
// World member function definitions ..

World::World(void) 
	: background_color(black), 
	tracer_ptr(NULL)
{
}

World::~World()
{
	if (tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = NULL;
	}

	// delete_objects();
}

void World::build(void)
{
	vp.set_hres((int)200);
	vp.set_vres((int)200);
	vp.set_pixel_size(1.0);
	vp.set_gamma(1.0);
	background_color = black;
	tracer_ptr = new SingleSphere(this);
	sphere.set_center(0.0);
	sphere.set_radius(85.0);


	im = new writeImage(vp.hres, vp.vres);
}

void World::render_scene(void) const
{
	RGBColor pixel_color;
	Ray ray;
	double zw = 100.0;
	double x, y;


	 /*open_window(vp.hres, vp.vres);*/
	


	ray.d = Vector3D(0, 0, -1);

	for (int r = 0; r < vp.vres; r++) // up
	{
		for (int c = 0; c <= vp.hres; c++)  //across
		{
			x = vp.s * (c - 0.5 * (vp.hres - 1.0));
			y = vp.s * (r - 0.5 * (vp.vres - 1.0));
			ray.o = Point3D(x, y, zw);
			pixel_color = tracer_ptr->trace_ray(ray);
			display_pixel(r, c, pixel_color);
		}
	}
}

//void World::open_window(const int hres, const int vres)
//{
//	im = new writeImage(hres, vres);
//}

// ------------------------------------------------------------------ clamp

RGBColor
World::max_to_one(const RGBColor& c) const {
	float max_value = max(c.r, max(c.g, c.b));

	if (max_value > 1.0)
		return (c / max_value);
	else
		return (c);
}


// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one

RGBColor
World::clamp_to_color(const RGBColor& raw_color) const {
	RGBColor c(raw_color);

	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
		c.r = 1.0; c.g = 0.0; c.b = 0.0;
	}

	return (c);
}

void World::display_pixel(const int row, const int column, const RGBColor& pixel_color) const
{ // a process that involves three steps: tone mapping, gamma correction and an integer mapping.

	RGBColor mapped_color;

	//if (vp.show_out_of_gamut)
	//	mapped_color = clamp_to_color(pixel_color);
	//else
	//	mapped_color = max_to_one(pixel_color);

	//if (vp.gamma != 1.0)
	//	mapped_color = mapped_color.powc(vp.inv_gamma);

	// have to start from max y coordinate to convert to screen coordinates
	int x = column;
	int y = vp.vres - row - 1;

	//paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
	//	(int)(mapped_color.g * 255),
	//	(int)(mapped_color.b * 255));

	im->setPixel(x, y, (int)(mapped_color.r * 255), (int)(mapped_color.g * 255), (int)(mapped_color.b * 255));

}
