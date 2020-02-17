#pragma once

#include "ViewPlane.h"
#include "Utilities/RGBColor.h"
#include "Tracer.h"
#include "Sphere.h"
#include "writeImage.h"


class World
{
public:

	ViewPlane vp;
	RGBColor background_color;
	Sphere sphere;
	Tracer* tracer_ptr;

	writeImage* im;

	World(void);

	~World();
	
	void build(void);

	void render_scene(void) const;

	

	//void open_window(const int hres, const int vres);

	RGBColor max_to_one(const RGBColor& c) const;

	RGBColor clamp_to_color(const RGBColor& raw_color) const;

	void display_pixel(const int row, const int column, const RGBColor& pixel_color) const;

};

