#include "Shaderec.h"

ShadeRec::ShadeRec(World& wr) 
	: hit_an_object(false), 
	local_hit_point(), 
	normal(), 
	color(black), 
	w(wr)
{}

ShadeRec::ShadeRec(const ShadeRec& sr)
	: hit_an_object(sr.hit_an_object), // har prøvd meg på ein copy-constructor. Anar ikkje om det er rett eller feil.
	local_hit_point(sr.local_hit_point),
	normal(sr.normal),
	color(sr.color), 
	w(sr.w) 
{}

ShadeRec::~ShadeRec(void)
{
}

ShadeRec& ShadeRec::operator=(const ShadeRec& rhs)
{
	// TODO: insert return statement here
}
