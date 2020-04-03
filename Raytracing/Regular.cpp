#include "Regular.h"

Regular::Regular(const int num)
	:Sampler(num)
{
	generate_samples();
}

void Regular::generate_samples(void)
{
	int n = (int)sqrt(num_samples);

	for (int p = 0; p < num_sets; p++)
	{		
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				Point2D sp((k + 0.5) / n, (j + 0.5) / n);
				samples.push_back(sp);
			}
		}
	}
}
