#include "Jittered.h"

#include <cmath>
#include "Utilities/Maths.h"

Jittered::Jittered(const int num)
	: Sampler(num)
{
	generate_samples();
}

void Jittered::generate_samples(void)
{

	int n = (int)sqrt(num_samples);

	for (int p = 0; p < num_sets; p++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				Point2D sp((k + rand_float()) / n, (j + rand_float()) / n);
				samples.push_back(sp);
			}
		}
	}

}
