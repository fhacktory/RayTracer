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

void
Plane::intersection()
{
}

void
Plane::calculateColor()
{
}