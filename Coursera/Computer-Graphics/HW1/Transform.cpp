// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	auto identity = mat3(1.0f);
	auto aaTransform = mat3
	(
		axis.x * axis.x, axis.y * axis.x, axis.z * axis.x,
		axis.x * axis.y, axis.y * axis.y, axis.z * axis.y,
		axis.x * axis.z, axis.y * axis.z, axis.z * axis.z
	);
	auto aStar = mat3
	(
		0, -axis.z, axis.y,
		axis.z, 0, -axis.x,
		-axis.y, axis.x, 0
	);

	auto angle = degrees * pi / 180;

  return mat3( (identity * cos(angle)) + (aaTransform * (1 - cos(angle))) + (aStar * sin(angle)));
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	auto rotated = rotate(degrees, up);
	eye = eye * rotated;
	up = up * rotated;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	auto orthogonalCords = glm::cross(eye, up);
	auto unit = glm::normalize(orthogonalCords);

	auto rotated = rotate(degrees, unit);
	eye = eye * rotated;
	up = up * rotated;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	vec3 u,v,w;
	vec3 center = vec3(0,0,1);

	a = eye - center;
	b = up;

	w = glm::normalize(a);




	//Recompute co-ordinates

  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
