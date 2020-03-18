#pragma once

#include <random>

std::random_device rd;
std::default_random_engine gen( rd() );
std::uniform_real_distribution<float> rand_float(0.0, 1.0);
std::uniform_int_distribution<int> rand_int(0, 100);


// lag tilfeldige tal slik: 
// distribution(generator)


//int rand_int();
//
//float rand_float();

inline double
max(double x0, double x1);

//inline int rand_int()
//{
//	return 0;
//}
//
//inline float rand_float()
//{
//	return 0.0f;
//}

inline double
max(double x0, double x1)
{
	return((x0 > x1) ? x0 : x1);
}
