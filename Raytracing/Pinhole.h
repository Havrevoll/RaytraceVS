#pragma once
#include "Camera.h"

#include "Utilities/Vector3D.h"
#include "Utilities/Point2D.h"

class Pinhole :
	public Camera
{
public:
	Pinhole(void);

	Vector3D ray_direction(const Point2D& p) const;

	virtual void render_scene(World& w);

	void set_view_distance(const int dist);
private:

	float d; // view-plane distance
	float zoom;
	
	// zoom factor
};

inline void Pinhole::set_view_distance(const int dist)
{
	d = dist;
}