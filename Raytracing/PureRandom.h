#pragma once
#include "Sampler.h"
class PureRandom :
	public Sampler
{
public:
	PureRandom(const int num);
private:
	virtual void generate_samples(void);

};

