#include "writeImage.h"

writeImage::writeImage(void)
{
}

writeImage::writeImage(const int hres, const int vres)
{
	image = new unsigned char[hres * vres * 3]; // lagar ein array for � skriva png til slutt
}

writeImage writeImage::makeImage(const int hres, const int vres)
{

	new unsigned char[hres * vres * 3];
}
