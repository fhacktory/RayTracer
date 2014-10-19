#include "../Headers/Plane.h"

/**
* Plane >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Plane::Plane() :
Object()
{
}

Plane::Plane(Plane const&)
{
}

Plane::~Plane()
{
	this->destroy();
}

void
Plane::destroy()
{
}

/**
* Plane >> OPERATORS
**/

Plane&
Plane::operator=(const Plane&)
{
	return *this;
}

/**
* Plane >> PRIVATE FUNCTIONS
**/

/**
* Plane >> PROTECTED FUNCTIONS
**/

/**
* Plane >> PUBLIC FUNCTIONS
**/

void
Plane::initialize(sf::Vector3f origine, sf::Color color, sf::Vector3f direction, float refraction, float reflection)
{
	this->direction = direction;
	Object::initialize(origine, color, refraction, reflection);
}

double
Plane::intersection(Ray* ray)
{
	double	det;
	double	X;
	double	Y;
	double	Z;
	double	D;

	auto rayDirection = ray->getDirection();
	auto rayOrigin = ray->getOrigin();

	X = rayOrigin->x - this->origine.x;
	Y = rayOrigin->y - this->origine.y;
	Z = rayOrigin->z - this->origine.z;
	D = -(this->origine.x * this->direction.x + this->origine.y * this->direction.y +
		this->origine.z * this->direction.z);

	det = -((this->direction.x * X + this->direction.y * Y + this->direction.z * Z + D) /
		(this->direction.x * rayDirection->x + this->direction.y * rayDirection->y +
		this->direction.z * rayDirection->z));
	if (det < 0.0)
		return 0.0f;
	return det;
}

void
Plane::calculateColor()
{
}