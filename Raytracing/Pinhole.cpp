#include "Pinhole.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"
#include "ViewPlane.h"

#include "World.h"

Pinhole::Pinhole(void)
{
}

Vector3D Pinhole::ray_direction(const Point2D& p) const
{
	Vector3D dir = p.x * u + p.y * v - d * w;
	dir.normalize();

	return (dir);
}

void Pinhole::render_scene(World& w)
{
	RGBColor L;
	ViewPlane vp(w.vp);
	Ray ray;
	int depth = 0; // recursive depth
	Point2D sp; // sample point in [0, 1] x [0, 1]
	Point2D pp;  // sample point on a pixel

	vp.s /= zoom;
	ray.o = eye;

	for (int r = 0; r < vp.vres; r++) // up
		for (int c = 0; c < vp.hres; c++) // across
		{
			L = black;

			for (int j = 0; j < vp.num_samples; j++)
			{
				sp = vp.sampler_ptr->sample_unit_square();
				pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
				pp.y = vp.s * (c - 0.5 * vp.vres + sp.y);
				ray.d = ray_direction(pp);
				L += w.tracer_ptr->trace_ray(ray, depth);
			}

			L /= vp.num_samples;
			L *= exposure_time;
			w.display_pixel(r, c, L);
		}

}
