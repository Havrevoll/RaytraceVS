#include "ViewPlane.h"

ViewPlane::ViewPlane(void)
	: hres(400), vres(400), s(1.0), gamma(1.0),inv_gamma(1.0), sampler_ptr(NULL)
{
}

ViewPlane::ViewPlane(const ViewPlane& vp)
	: hres(vp.hres), vres(vp.vres), s(vp.s), gamma(vp.gamma), inv_gamma(vp.inv_gamma), sampler_ptr(vp.sampler_ptr)
{
}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs)
{
	if (this == &rhs)
		return (*this);

	hres = rhs.hres;
	vres = rhs.vres;
	s = rhs.s;
	gamma = rhs.gamma;
	inv_gamma = rhs.inv_gamma;
	sampler_ptr = rhs.sampler_ptr;

	return (*this);

}

ViewPlane::~ViewPlane()
{
	//if (sampler_ptr) {
	//	delete sampler_ptr;
	//	sampler_ptr = NULL;
	//}
}

void ViewPlane::set_sampler(Sampler* sp)
{
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	num_samples = sp->get_num_samples();
	sampler_ptr = sp;
	// sampler_ptr->map_samples_to_unit_disk();
}

void ViewPlane::set_samples(const int n)
{
	num_samples = n;

	if (sampler_ptr)
	{
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if (num_samples > 1)
	{
		sampler_ptr = new MultiJittered(num_samples);
	}
	else
	{
		sampler_ptr = new Regular(1);
	}
}
