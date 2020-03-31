#include "MultiJittered.h"

#include "Utilities/Maths.h"

MultiJittered::MultiJittered(const int num)
	: Sampler(num)
{
	generate_samples();
}


void MultiJittered::generate_samples(void)
{
	/* Henta frå Graphic Gems IV, side 373. Eigentleg eit c-program.
	MultiJitter() takes an array of Point2D's and the dimension, and fills the
	the array with the generated sample points.

	p[] must have length m*n (eg brukar n*n)
	m is the number of columns of cells.
	n is the number of rows of cells.
	*/

	int n = (int)sqrt(num_samples);

	double subcell_width = 1.0/(num_samples);
	
	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the 
// initial patterns
	Point2D fill_point;
	for (int j = 0; j < num_samples * num_sets; j++)
		samples.push_back(fill_point);

	for (int p = 0; p < num_sets; p++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0.0, subcell_width);
				samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0.0, subcell_width);

			}
		}
	}

	/*shuffe x coordinates within each column of cells*/
	for (int p = 0; p < num_sets; p++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int k = rand_int(j, n - 1);
				double t = samples[i * n + j + p * num_samples].x;
				samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
				samples[i * n + k + p * num_samples].x = t;
			}
		}
	}

	/*shuffe y coordinates within each column of cells*/
	for (int p = 0; p < num_sets; p++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int k = rand_int(j, n - 1);
				double t = samples[j * n + i + p * num_samples].y;
				samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
				samples[k * n + i + p * num_samples].y = t;
			}
		}
	}


}
