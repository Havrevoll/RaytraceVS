#pragma once

#include "Point3D.h"
#include "Vector3D.h"

class Ray {
	public:
	
		Point3D			o;  	// origin 
		Vector3D		d; 		// direction 
		
		Ray(void);			// default constructor
		
		Ray(const Point3D& origin, const Vector3D& dir);	// constructor
		
		Ray(const Ray& ray); 		// copy constructor
		
		Ray& 						// assignment operator
		operator= (const Ray& rhs);
		 								
		~Ray(void); // destructor
};


