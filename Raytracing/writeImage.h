#pragma once

class writeImage
{
public:
	writeImage(void);

	writeImage(const int hres, const int vres);

	writeImage(const writeImage& im);

	writeImage& operator=(const writeImage& im);

	void setPixel(const int x, const int y, int red, int green, int blue);

	void saveImage(void);
	
private:
	unsigned char* image;

	int hres;
	int vres;
	int len;
	

};

