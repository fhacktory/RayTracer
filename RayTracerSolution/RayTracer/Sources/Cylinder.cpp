#include "../Headers/Cylinder.h"

/**
* Cylinder >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Cylinder::Cylinder() :
Object()
{
}

Cylinder::Cylinder(Cylinder const&)
{
}

Cylinder::~Cylinder()
{
	this->destroy();
}

void
Cylinder::destroy()
{
}

/**
* Cylinder >> OPERATORS
**/

Cylinder&
Cylinder::operator=(const Cylinder&)
{
	return *this;
}

/**
* Cylinder >> PRIVATE FUNCTIONS
**/

/**
* Cylinder >> PROTECTED FUNCTIONS
**/

/**
* Cylinder >> PUBLIC FUNCTIONS
**/

void
Cylinder::initialize(sf::Vector3f origine, sf::Color color, sf::Vector3f direction, float radius, float refraction, float reflection)
{
	this->radius = radius;
	this->direction = direction;
	Object::initialize(origine, color, refraction, reflection);
}

void
Cylinder::intersection()
{
}

void
Cylinder::calculateColor()
{
}