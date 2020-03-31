#include "NRooks.h"

#include "Utilities/Maths.h"

NRooks::NRooks(const int num)
	: Sampler(num)
{
	generate_samples();
}

void NRooks::generate_samples(void)
{
	// generate samples along main diagonal

	for (int p = 0; p < num_sets; p++)
	{
		
		for (int j = 0; j < num_samples; j++)
		{
			Point2D pv;
			pv.x = (j + rand_float()) / num_samples;
			pv.y = (j + rand_float()) / num_samples;
			samples.push_back(pv);
		}
	}
	shuffle_x_coordinates();
	shuffle_y_coordinates();
}

void NRooks::shuffle_x_coordinates(void) {
	for (int p = 0; p < num_sets; p++)
	{
		
		for (int i = 0; i < num_samples - 1; i++)
		{
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].x;
			samples[i + p * num_samples + 1].x = samples[target].x;
			samples[target].x = temp;
		}
	}
}

void NRooks::shuffle_y_coordinates(void) {
	for (int p = 0; p < num_sets; p++)
	{

		for (int i = 0; i < num_samples - 1; i++)
		{
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].y;
			samples[i + p * num_samples + 1].y = samples[target].y;
			samples[target].y = temp;
		}
	}
}