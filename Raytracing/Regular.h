#pragma once
#include "Sampler.h"
class Regular :
	public Sampler
{
public:
	Regular(const int num);
private:
	virtual void generate_samples(void);

};

