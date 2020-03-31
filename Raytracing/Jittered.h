#pragma once
#include "Sampler.h"

class Jittered :
	public Sampler
{
public:
	Jittered(const int num);
private:
	virtual void generate_samples(void);

};

