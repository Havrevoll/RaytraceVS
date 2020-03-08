#include "MultipleObjects.h"
#include "World.h"
#include "Shaderec.h"

MultipleObjects::MultipleObjects(void) : Tracer()
{

}

MultipleObjects::MultipleObjects(World* _worldPtr) : Tracer(_worldPtr)
{

}

RGBColor MultipleObjects::trace_ray(const Ray& ray) const
{
	ShadeRec sr(world_ptr->hit_bare_bones_objects(ray));
	if (sr.hit_an_object)
		return (sr.color);
	else
		return (world_ptr->background_color);
	
}
