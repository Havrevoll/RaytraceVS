#pragma once


#include <vector>



#include "Utilities/Point2D.h"


class Sampler
{
protected:
	int num_samples; // the number of sample points in a pattern
	int num_sets; // the number of sample sets (patterns) stored
	std::vector<Point2D> samples; //sample points on a unit square
	std::vector<int> shuffled_indices; // shuffled samples array indices
	unsigned long count; // the current number of sample points used
	int jump; // random index jump
public:

	//Sampler(void);

	Sampler(int num);

	Sampler(void);

	virtual ~Sampler(void);

	int get_num_samples(void);



	// generate sample patterns in a unit square
	virtual void generate_samples() = 0;

	// set up the randomly shuffled indices
	void setup_shuffled_indices();

	// randomly shuffle the samples in each pattern
	void shuffle_samples();

	// get next sample on unit square
	Point2D sample_unit_square();
};

inline int Sampler::get_num_samples(void)
{
	return num_samples;
}


