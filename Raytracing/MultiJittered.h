#pragma once
#include "Sampler.h"
class MultiJittered :
	public Sampler
{
public:
	MultiJittered(const int num);
private:
	virtual void generate_samples(void);

};

