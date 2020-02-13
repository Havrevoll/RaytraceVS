#include "writeImage.h"

writeImage::writeImage(const int hres, const int vres)
{
	image = new unsigned char[hres * vres * 3]; // lagar ein array for å skriva png til slutt
}
