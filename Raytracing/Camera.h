#pragma once

#include "Utilities/Point3D.h"
#include "Utilities/Vector3D.h"

class World;

class Camera
{
public:

	// constructor, access functions etc.
	Camera(void);

	~Camera();

	void set_eye(const int x, const int y, const int z);

	void set_lookat(const int x, const int y, const int z);

	void set_view_distance(const int d); // set d

	

	void compute_uvw(void);

	virtual void render_scene(World& w) = 0;

protected:
	
	Point3D eye;
	Point3D lookat;
	Vector3D up;
	Vector3D u, v, w;
	float exposure_time;
};

inline void Camera::set_eye(const int x, const int y, const int z)
{
	eye.x = x;
	eye.y = y;
	eye.z = z;

}

inline void Camera::set_lookat(const int x, const int y, const int z)
{
	lookat.x = x;
	lookat.y = y;
	lookat.z = z;
}

