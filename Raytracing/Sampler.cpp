#include "Sampler.h"

#include <cmath>
#include <algorithm>
#include "Utilities/Maths.h"
#include "Utilities/Constants.h"

//Sampler::Sampler(void)
//	: num_samples(1) {
//
//}

Sampler::Sampler(const int num)
	: num_samples(num), count(0), jump(0), num_sets(83)
{
	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(void)
	: num_samples(1), count(0), jump(0), num_sets(83)
{
	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const int ns, const int n_sets)
	: num_samples(ns),
	num_sets(n_sets),
	count(0),
	jump(0) {
	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
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
	shuffled_indices.reserve(num_samples * num_sets);
	std::vector<int> indices;

	for (int j = 0; j < num_samples; j++)
	{
		indices.push_back(j);
	}

	for (int p = 0; p < num_sets; p++)
	{
		std::shuffle(indices.begin(), indices.end(), global_urng());

		for (int j = 0; j < num_samples; j++)
		{
			shuffled_indices.push_back(indices[j]);
		}
	}


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

	return (samples[jump + shuffled_indices[jump+ count++ % num_samples]]);
}

Point2D Sampler::sample_unit_disk()
{
	if (count % num_samples == 0) // start of a new pixel
	{
		jump = (rand_int() % num_sets) * num_samples;
	}
	return (disk_samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

Point3D Sampler::sample_hemisphere()
{
	if (count % num_samples == 0) // start of a new pixel
	{
		jump = (rand_int() % num_sets) * num_samples;
	}
	return (hemisphere_samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

void Sampler::map_samples_to_unit_disk(void) {
	int size = samples.size();
	float r, phi;
	Point2D sp;
	
	disk_samples.reserve(size);

	for (int j = 0; j < size; j++)
	{
		// map sample point to [-1,1] [-1,1]

		sp.x = 2.0 * samples[j].x - 1.0;
		sp.y = 2.0 * samples[j].y - 1.0;

		if (sp.x > -sp.y) //sectors 1 and 2
		{			
			if (sp.x>sp.y) // sector 1
			{
				r = sp.x;
				phi = sp.y / sp.x;
			}
			else
			{ // sector 2
				r = sp.y;
				phi = 2 - sp.x / sp.y;
			}
		}
		else
		{ //sectors 3 and 4
			if (sp.x < sp.y) // sector 3
			{
				r = -sp.x;
				phi = 4 + sp.y / sp.x;
			}
			else
			{ // sector 4
				r = -sp.y;
				if (sp.y != 0.0) //avoid division by zero at origin
				{
					phi = 6 - sp.x / sp.y;
				}
				else
				{
					phi = 0.0;
				}
			}
		}

		phi *= PI / 4.0;

		disk_samples[j].x = r * cos(phi);
		disk_samples[j].y = r * sin(phi);

	}
}

void Sampler::map_samples_to_hemisphere(const float e)
{
	int size = samples.size();
	hemisphere_samples.reserve(num_samples * num_sets);

	for (int j = 0; j < size; j++)
	{
		float cos_phi = cos(2.0 * PI * samples[j].x);
		float sin_phi = sin(2.0 * PI * samples[j].x);
		float cos_theta = pow((1.0 - samples[j].y), 1.0 / (e + 1.0));
		float sin_theta = sqrt(1.0 - cos_theta * cos_theta);
		float pu = sin_theta * cos_phi;
		float pv = sin_theta * sin_phi;
		float pw = cos_theta;





		hemisphere_samples.push_back(Point3D(pu, pv, pw));
	}
}