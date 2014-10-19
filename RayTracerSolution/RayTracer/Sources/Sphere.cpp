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

void	
Sphere::intersection()
{
}

void	
Sphere::calculateColor()
{
}