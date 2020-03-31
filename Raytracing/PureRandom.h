#pragma once
#include "Sampler.h"
class PureRandom :
	public Sampler
{
private:
	virtual void generate_samples(void);

};

