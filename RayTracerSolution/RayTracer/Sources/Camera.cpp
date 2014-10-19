#include "../Headers/Camera.h"

/**
* Camera >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Camera::Camera()
{
}

Camera::Camera(Camera const&) //:
{
}

Camera::~Camera()
{
	this->destroy();
}

void
Camera::destroy()
{
}

/**
* Camera >> OPERATORS
**/

Camera&
Camera::operator=(const Camera&)
{
	return *this;
}

/**
* Camera >> PRIVATE FUNCTIONS
**/

/**
* Camera >> PROTECTED FUNCTIONS
**/

/**
* Camera >> PUBLIC FUNCTIONS
**/

bool
Camera::initialize(unsigned int width, unsigned int height)
{
	this->viewportWidth = width;
	this->viewportHeight = height;

	this->origin.x = 0;
	this->origin.y = 0;
	this->origin.z = 0;

	this->direction.x = 0;
	this->direction.y = 0;
	this->direction.z = 1;

	this->fovX = 0.75f;
	this->fovY = ((float)width / (float)height) * this->fovX;

	return true;
}

sf::Vector3f*
Camera::getOrigin()
{
	return &this->origin;
}

sf::Vector3f*
Camera::getDirection()
{
	return &this->direction;
}

unsigned int
Camera::getViewportWidth()
{
	return this->viewportWidth;
}

unsigned int
Camera::getViewportHeight()
{
	return this->viewportHeight;
}

float
Camera::getFovX()
{
	return this->fovX;
}

float
Camera::getFovY()
{
	return this->fovY;
}