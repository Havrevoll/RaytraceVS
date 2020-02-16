#pragma once
class writeImage
{
public:
	writeImage(void);

	writeImage(const int hres, const int vres);

	void setPixel(const int x, const int y, int red, int green, int blue);
	
private:
	unsigned char* image;

	int hres;
	int vres;
	

};

