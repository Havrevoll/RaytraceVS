#pragma once
#include "Sampler.h"
#include "MultiJittered.h"
#include "Regular.h"

class ViewPlane
{
public:
	int hres; // horizontal image resolution
	int vres; // vertical image resolution
	float s; // pixel size
	float gamma; // monitor gamma factor
	float inv_gamma; // one over gamma
	bool			show_out_of_gamut;			// display red if RGBColor out of gamut

	int num_samples;

	Sampler* sampler_ptr;

public:
	ViewPlane(void);

	ViewPlane(const ViewPlane& vp);

	ViewPlane& operator= (const ViewPlane& rhs);

	~ViewPlane();

	void set_hres(const int h_res);
	void set_vres(const int v_res);

	void set_pixel_size(const float size);

	void set_gamma(const float g);

	void set_num_samples(const int num);

	void set_sampler(Sampler* sp);

	void set_samples(const int n);

};

inline void ViewPlane::set_hres(const int h_res)
{
	hres = h_res;
}

inline void ViewPlane::set_vres(const int v_res)
{
	vres = v_res;
}

inline void ViewPlane::set_pixel_size(const float size)
{
	s = size;
}

inline void ViewPlane::set_gamma(const float g)
{
	gamma = g;
	inv_gamma = 1.0 / gamma;
}

inline void ViewPlane::set_num_samples(const int num)
{
	num_samples = num;
}



