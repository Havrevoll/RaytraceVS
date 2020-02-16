#include "writeImage.h"

writeImage::writeImage(void)
{
}

writeImage::writeImage(const int hr, const int vr)
{
	image = new unsigned char[hr * vr * 3]; // lagar ein array for å skriva png til slutt
	hres = hr;
	vres = vr;
}

void writeImage::setPixel(const int x, const int y, int red, int green, int blue)
{
	data[x * 3 + (vres - 1 - y) * hres * 3] = red;
	data[x * 3 + (vres - 1 - y) * hres * 3 + 1] = green;
	data[x * 3 + (vres - 1 - y) * hres * 3 + 2] = blue;
	
}
