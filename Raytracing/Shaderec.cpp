#include "Shaderec.h"

ShadeRec::ShadeRec(World& wr) 
	: hit_an_object(false), 
	local_hit_point(), 
	normal(), 
	color(black), 
	w(wr)
{
}

ShadeRec::ShadeRec(const ShadeRec& sr)
{
}

ShadeRec::~ShadeRec(void)
{
}

ShadeRec& ShadeRec::operator=(const ShadeRec& rhs)
{
	// TODO: insert return statement here
}
