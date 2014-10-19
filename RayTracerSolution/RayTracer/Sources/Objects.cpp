#include "../Headers/Object.h"

/**
* Object >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Object::Object() :
refraction(0),
reflection(0)
{
}

Object::Object(Object const&)
{
}

Object::~Object()
{
	this->destroy();
}

void
Object::destroy()
{
}

/**
* Object >> OPERATORS
**/

Object&
Object::operator=(const Object&)
{
	return *this;
}

/**
* Object >> PRIVATE FUNCTIONS
**/

/**
* Object >> PROTECTED FUNCTIONS
**/

/**
* Object >> PUBLIC FUNCTIONS
**/

void
Object::initialize(sf::Vector3f origine, sf::Color color, float refraction, float reflection)
{
	this->color = color;
	this->origine = origine;
	this->refraction = refraction;
	this->reflection = reflection;
}