#pragma once

#include "ViewPlane.h"
#include "Utilities/RGBColor.h"
#include "Tracer.h"
#include "Sphere.h"


class World
{
public:

	ViewPlane vp;
	RGBColor background_color;
	Sphere sphere;
	Tracer* tracer_ptr;

	World(void);

	~World();
	
	void build(void);

	void render_scene(void) const;

	void open_window(const int hres, const int vres) const;

	void display_pixel(const int row, const int column, const RGBColor& pixel_color) const;

};

