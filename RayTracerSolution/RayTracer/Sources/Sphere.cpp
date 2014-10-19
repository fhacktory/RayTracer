#include "../Headers/Sphere.h"

/**
* Sphere >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Sphere::Sphere() :
Object()
{
}

Sphere::Sphere(Sphere const&)
{
}

Sphere::~Sphere()
{
	this->destroy();
}

void
Sphere::destroy()
{
}

/**
* Sphere >> OPERATORS
**/

Sphere&
Sphere::operator=(const Sphere&)
{
	return *this;
}

/**
* Sphere >> PRIVATE FUNCTIONS
**/

/**
* Sphere >> PROTECTED FUNCTIONS
**/

/**
* Sphere >> PUBLIC FUNCTIONS
**/

void
Sphere::initialize(sf::Vector3f origine, sf::Color color, float radius, float refraction, float reflection)
{
	this->radius = radius;
	Object::initialize(origine, color, refraction, reflection);
}

sf::Color*
Sphere::intersection(Ray* ray)
{
	double	a;
	double	b;
	double	c;
	double	det;
	auto rayDirection = ray->getDirection();
	auto rayOrigin = ray->getOrigin();

	a = rayDirection->x * rayDirection->x +
		rayDirection->y * rayDirection->y +
		rayDirection->z * rayDirection->z;
	b = 2 * (rayDirection->x * (rayOrigin->x - this->origine.x) +
		rayDirection->y * (rayOrigin->y - this->origine.y) +
		rayDirection->z * (rayOrigin->z - this->origine.z));
	c = this->origine.x * this->origine.x + this->origine.y * this->origine.y +
		this->origine.z * this->origine.z +
		rayOrigin->x * rayOrigin->x + rayOrigin->y * rayOrigin->y + rayOrigin->z * rayOrigin->z -
		2 * (this->origine.x * rayOrigin->x + this->origine.y * rayOrigin->y +
		this->origine.z * rayOrigin->z) -
		this->radius * this->radius;
	det = b * b - (4 * a * c);
	if (det < 0)
		return new sf::Color(0, 0, 0);
	return &this->color;
}

void	
Sphere::calculateColor()
{
}