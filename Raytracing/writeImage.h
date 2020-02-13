#pragma once
class writeImage
{
public:
	writeImage(void);

	writeImage(const int hres, const int vres);

	writeImage makeImage(const int hres, const int vres);

private:
	unsigned char* image;

	

};

