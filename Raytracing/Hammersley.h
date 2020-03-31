#pragma once
#include "Sampler.h"
class Hammersley :
	public Sampler
{
private:
	virtual void generate_samples(void);

};

