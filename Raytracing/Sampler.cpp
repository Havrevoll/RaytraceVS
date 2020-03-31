#include "Sampler.h"

#include <cmath>
#include "Utilities/Maths.h"

//Sampler::Sampler(void)
//	: num_samples(1) {
//
//}

Sampler::Sampler(const int num)
	: num_samples(num), count(0), jump(0), num_sets(83)
{
	1;
}

Sampler::Sampler(void)
	: num_samples(1), count(0), jump(0), num_sets(83)
{
	1;
}

 Sampler::~Sampler(void)
{
}



void Sampler::generate_samples()
{
	// TODO: Add your implementation code here.
}


// set up the randomly shuffled indices
void Sampler::setup_shuffled_indices()
{
	// TODO: Add your implementation code here.
}


// randomly shuffle the samples in each pattern
void Sampler::shuffle_samples()
{
	// TODO: Add your implementation code here.
}


Point2D Sampler::sample_unit_square()
{
	if (count % num_samples == 0) // start of a new pixel
		jump = (rand_int() % num_sets) * num_samples;

	return (samples[jump + count++ % num_samples]);
}
