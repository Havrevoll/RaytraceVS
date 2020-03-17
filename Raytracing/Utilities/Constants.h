#pragma once

#include <stdlib.h>
#include "RGBColor.h"
//#include <random>

const double 	PI 			= 3.1415926535897932384;
const double 	TWO_PI 		= 6.2831853071795864769;
const double 	PI_ON_180 	= 0.0174532925199432957;
const double 	invPI 		= 0.3183098861837906715;
const double 	invTWO_PI 	= 0.1591549430918953358;

const double 	kEpsilon 	= 0.0001; 
const double	kHugeValue	= 1.0E10;

const RGBColor	black(0.0);
const RGBColor	white(1.0);
const RGBColor	red(1.0, 0.0, 0.0);

const float 	invRAND_MAX = 1.0 / (float)RAND_MAX;

const int cCx = 500;
const int cCy = 500;

// Legg inn oppløysinga som to int som gjeld i heile programmet. Static?


// std::random_device rd;
//std::default_random_engine gen;//( rd() );
//std::uniform_real_distribution<float> distr(0.0, 1.0);

// lag tilfeldige tal slik: 
// distr(gen)