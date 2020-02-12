
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
	vp.set_hres(200);
	vp.set_vres(200);
	vp.set_pixel_size(1.0);
	vp.set_gamma(1.0);
	background_color = black;
	tracer_ptr = new SingleSphere(this);
	sphere.set_center(0.0);
	sphere.set_radius(85.0);
}

void World::render_scene(void) const
{
}

void World::open_window(const int hres, const int vres) const
{
}

void World::display_pixel(const int row, const int column, const RGBColor& pixel_color) const
{
}
