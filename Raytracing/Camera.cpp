#include "Camera.h"

#include <cmath>
#include "Utilities/Maths.h"

Camera::Camera(void)

{
}

Camera::~Camera()
{
}



void Camera::compute_uvw(void)
{

	if (isEqual(eye.x,lookat.x) && isEqual(eye.z,lookat.z))
	{
		u = Vector3D(0.0, 0.0, 1.0);
		v = Vector3D(1.0, 0.0, 0.0);
		w = Vector3D(0.0, 1.0, 0.0);
	} 
	else
	{
		w = eye - lookat;
		w.normalize();
		u = up ^ w;
		u.normalize();
		v = w ^ u;
	}
	
	
}
