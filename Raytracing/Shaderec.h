#pragma once

class World;

#include "Utilities/Point3D.h"
/*#include "Utilities/Vector3D.h"*/
#include "Utilities/RGBColor.h"
#include "Utilities/Normal.h"


class ShadeRec
{
public:
	bool hit_an_object; // did the ray hit an object?
	Point3D local_hit_point; // world coordinates of hit point
	Normal normal; // normal at hit point
	RGBColor color; //used in chapter 3 only
	World& w; // world reference for shading

	ShadeRec(World& wr); // constructor
	ShadeRec(const ShadeRec& sr); //copy constructor
	~ShadeRec(void); //destructor

	//ShadeRec& operator= (const ShadeRec& rhs); // assignment operator


};

