#include "Hammersley.h"

Hammersley::Hammersley(const int num)
	: Sampler(num)
{
	generate_samples();
}



// ---------------------------------------------------------------- phi

double Hammersley::phi(int j) {
	double x = 0.0;
	double f = 0.5;

	while (j) {
		x += f * (double)(j % 2);
		j /= 2;
		f *= 0.5;
	}

	return (x);
}


void Hammersley::generate_samples(void)
{
	for (int p = 0; p < num_sets; p++)
		for (int j = 0; j < num_samples; j++) {
			Point2D pv((float)j / (float)num_samples, phi(j));
			samples.push_back(pv);
		}
}
