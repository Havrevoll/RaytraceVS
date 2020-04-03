#pragma once
#include "Sampler.h"
class Hammersley :
	public Sampler
{
public:
	Hammersley(const int num);
private:
	double phi(int j);
	virtual void generate_samples(void);

};

