#pragma once


#include <vector>



#include "Utilities/Point2D.h"
#include "Utilities/Point3D.h"


class Sampler
{
protected:
	int num_samples; // the number of sample points in a pattern
	int num_sets; // the number of sample sets (patterns) stored
	std::vector<Point2D> samples; //sample points on a unit square
	std::vector<int> shuffled_indices; // shuffled samples array indices
	std::vector<Point2D> disk_samples; // sample points on a unit disk
	std::vector<Point3D> hemisphere_samples; // sample points on a hemisphere
	
	unsigned long count; // the current number of sample points used
	int jump; // random index jump
public:

	//Sampler(void);

	Sampler(int num);

	Sampler(void);

	Sampler(const int ns, const int n_sets);

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

	Point2D sample_unit_disk();

	Point3D sample_hemisphere();

	void map_samples_to_unit_disk(void);

	void map_samples_to_hemisphere(const float e);
};

inline int Sampler::get_num_samples(void)
{
	return num_samples;
}


