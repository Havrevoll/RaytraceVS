#include "writeImage.h"
#include <cstring>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Utilities/stb_image_write.h"
#include <Windows.h>
#include "Utilities/Constants.h"

//extern HWND hWnd;
extern COLORREF arr[];




writeImage::writeImage(void)
{
}

writeImage::writeImage(const int hr, const int vr)
{


	hres = hr;
	vres = vr;
	len = hres * vres * 3;
	image = new unsigned char[len]; // lagar ein array for å skriva png til slutt

}

writeImage::writeImage(const writeImage& im)
{
	hres = im.hres;
	vres = im.vres;

	len = hres * vres * 3;

	image = new unsigned char[len + 1];
	std::memcpy(image, im.image, len);
}

writeImage& writeImage::operator=(const writeImage& im) //dokumentert i c++ primer plus side 659-660
{
	if (this == &im) // object assigned to itself
		return *this; // all done
	delete[] image; // free old string
	len = im.len;
	image = new unsigned char[len + 1]; // get space for new string
	std::memcpy(image, im.image, len); // copy the string
	return *this; // return reference to invoking object
}

void writeImage::setPixel(const int x, const int y, int red, int green, int blue)
{
	image[x * 3 + y * hres * 3] = red;
	image[x * 3 + y * hres * 3 + 1] = green;
	image[x * 3 + y * hres * 3 + 2] = blue;
	
	arr[cCx * y + x] = RGB(blue, green, red);
	
//	InvalidateRect(hWnd, NULL, TRUE);
}

void writeImage::saveImage(void)
{
	stbi_write_png("foo_out.png", hres, vres, 3, image, 0);
}