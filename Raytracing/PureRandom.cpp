#include "PureRandom.h"

#include "Utilities/Maths.h"

PureRandom::PureRandom(const int num)
	: Sampler(num)
{
	generate_samples();
}

void PureRandom::generate_samples(void)
{

	int n = (int)sqrt(num_samples);

	for (int p = 0; p < num_sets; p++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				Point2D sp(rand_float(), rand_float());
				samples.push_back(sp);
			}
		}
	}
}
