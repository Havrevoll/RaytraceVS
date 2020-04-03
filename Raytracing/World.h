#pragma once

#include <vector>

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
	//Sphere sphere;
	Tracer* tracer_ptr;
	std::vector<GeometricObject*> objects;


	writeImage* im;

	World(void);

	~World();
	
	void build(void);

	void render_scene(void) const;

	void render_perspective(void) const;

	void add_object(GeometricObject* object_ptr);

	ShadeRec hit_bare_bones_objects(const Ray& ray);

	//void open_window(const int hres, const int vres);

	RGBColor max_to_one(const RGBColor& c) const;

	RGBColor clamp_to_color(const RGBColor& raw_color) const;

	void display_pixel(const int row, const int column, const RGBColor& pixel_color) const;

};

inline void World::add_object(GeometricObject* object_ptr) {
	objects.push_back(object_ptr);
}

