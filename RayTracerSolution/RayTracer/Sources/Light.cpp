#include "../Headers/Light.h"

/**
* Light >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Light::Light() :
Object()
{
}

Light::Light(Light const&)
{
}

Light::~Light()
{
	this->destroy();
}

void
Light::destroy()
{
}

/**
* Light >> OPERATORS
**/

Light&
Light::operator=(const Light&)
{
	return *this;
}

/**
* Light >> PRIVATE FUNCTIONS
**/

/**
* Light >> PROTECTED FUNCTIONS
**/

/**
* Light >> PUBLIC FUNCTIONS
**/

void
Light::initialize()
{
	Object::initialize(origine, color, refraction, reflection);
}

sf::Color*
Light::intersection(Ray* ray)
{
	return nullptr;
}

void
Light::calculateColor()
{
}