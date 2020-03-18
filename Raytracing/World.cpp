
#include "World.h"
#include "Utilities/Constants.h"


// geometric objects

#include "Sphere.h"
#include "Plane.h"

// Tracers

//#include "SingleSphere.h"
#include "MultipleObjects.h"

// Utilities

#include "Utilities/Vector3D.h"
#include "Utilities/Point3D.h"
#include "Utilities/Point2D.h"
#include "Utilities/Normal.h"
#include "Shaderec.h"
#include "Utilities/Ray.h"
#include "Utilities/Maths.h"
#include <Windows.h>




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
	vp.set_hres(cCx);
	vp.set_vres(cCy);

	vp.set_pixel_size(1.0);
	vp.set_gamma(1.0);
	vp.set_num_samples(16);

	background_color = black;

	tracer_ptr = new MultipleObjects(this);

	// use access functions to set sphere center and radius
	Sphere* sphere_ptr = new Sphere;
	sphere_ptr->set_center(0, -25, 0);
	sphere_ptr->set_radius(80);
	sphere_ptr->set_color(1, 0, 0); // red
	add_object(sphere_ptr);

	// use constructor to set sphere center and radius
	sphere_ptr = new Sphere(Point3D(20, 30, 0), 60);
	sphere_ptr->set_color(1.0, 1.0, 0); // yellow
	add_object(sphere_ptr);

	sphere_ptr = new Sphere(Point3D(60, 00, 40), 50);
	sphere_ptr->set_color(0.4, 0.6, 0.9); 
	add_object(sphere_ptr);

	//Plane* plane_ptr = new Plane(Point3D(0, 0, 0), Normal(0, 1, 1));
	//plane_ptr->set_color(0.0, 0.3, 0.0); // dark green
	//add_object(plane_ptr);


	im = new writeImage(vp.hres, vp.vres);
	
}

VOID toScreen(VOID);
void World::render_scene(void) const
{
	RGBColor pixel_color;
	Ray ray;
	double zw = 100.0;

	int n = (int)sqrt((float)vp.num_samples);
	Point2D pp; // sample point on a pixel

	
	 /*open_window(vp.hres, vp.vres);*/
	


	ray.d = Vector3D(0, 0, -1);

	for (int r = 0; r < vp.vres; r++) // up
	{
		for (int c = 0; c <= vp.hres; c++)  //across
		{
			pixel_color = black;

			for (int p = 0; p < vp.num_samples; p++) // up pixel
			{
				
					pp.x = vp.s * (c - 0.5 * vp.hres + rand_float(gen));
					pp.y = vp.s * (r - 0.5 * vp.vres + rand_float(gen));
					ray.o = Point3D(pp.x, pp.y, zw);
					pixel_color += tracer_ptr->trace_ray(ray);
				
			}
			
			pixel_color /= vp.num_samples; // average the colors
			display_pixel(r, c, pixel_color);

			
		}
		
	}

	toScreen();
	im->saveImage();
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

	if (vp.show_out_of_gamut)
		mapped_color = clamp_to_color(pixel_color);
	else
		mapped_color = max_to_one(pixel_color);

	if (vp.gamma != 1.0)
		mapped_color = mapped_color.powc(vp.inv_gamma);

	// have to start from max y coordinate to convert to screen coordinates
	int x = column;
	int y = vp.vres - row - 1;

	//paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
	//	(int)(mapped_color.g * 255),
	//	(int)(mapped_color.b * 255));

	im->setPixel(x, y, (int)(pixel_color.r * 255), (int)(pixel_color.g * 255), (int)(pixel_color.b * 255));

}

ShadeRec World::hit_bare_bones_objects(const Ray& ray) 
{
	ShadeRec sr(*this);
	double t;
	double tmin = kHugeValue;
	int num_objects = objects.size();
	for (int j = 0; j < num_objects; j++)
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object = true;
			tmin = t;
			sr.color = objects[j]->get_color();
		}
	return (sr);
}
