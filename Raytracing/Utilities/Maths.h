#pragma once

#include <random>

#include "Utilities/AlmostEquals.h"

//static std::random_device rd;
//static std::default_random_engine gen( rd() );
//static std::uniform_real_distribution<float> rand_float(0.0, 1.0);
//static std::uniform_int_distribution<int> rand_int(0, RAND_MAX);

// kall dei slik: rand_float(gen) og rand_int(gen)


// Dei fylgjande er henta herifrå: https://isocpp.org/files/papers/n3551.pdf
static std::default_random_engine& global_urng()
{
	static std::default_random_engine u{};
	return u;
}
static void randomize()
{
	static std::random_device rd{};
	global_urng().seed(rd());
}
static int pick_a_number(int from, int thru)
{
	static std::uniform_int_distribution<> d{};
	using parm_t = decltype(d)::param_type;
	return d(global_urng(), parm_t{ from, thru });
}
static double pick_a_number(double from, double upto)
{
	static std::uniform_real_distribution<> d{};
	using parm_t = decltype(d)::param_type;
	return d(global_urng(), parm_t{ from, upto });
}

inline double rand_float() {
	return (pick_a_number(0.0, 1.0));
}

inline double rand_float(double from, double to) {
	return (pick_a_number(from, to));
}

inline int rand_int() {
	return (pick_a_number(0, RAND_MAX));
}

inline int rand_int(int from, int to) {
	return (pick_a_number(from, to));
}

inline double
max(double x0, double x1);


inline double
max(double x0, double x1)
{
	return((x0 > x1) ? x0 : x1);
}

static bool isEqual(double left, double right)
{
	//double left = eye.x; // something
	//double right = lookat.x; // something
	const FloatingPoint<double> lhs(left), rhs(right);

	return lhs.AlmostEquals(rhs);

	
}