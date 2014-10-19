#include "../Headers/Ray.h"

/**
* Ray >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Ray::Ray()
{
}

Ray::Ray(Ray const&) //:
{
}

Ray::~Ray()
{
	this->destroy();
}

void
Ray::destroy()
{
}

/**
* Ray >> OPERATORS
**/

Ray&
Ray::operator=(const Ray&)
{
	return *this;
}

/**
* Ray >> PRIVATE FUNCTIONS
**/

void
Ray::normalize(sf::Vector3f* vector)
{
	float	norm;

	norm = sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
	vector->x = vector->x / norm;
	vector->y = vector->y / norm;
	vector->z = vector->z / norm;
}

/**
* Ray >> PROTECTED FUNCTIONS
**/

/**
* Ray >> PUBLIC FUNCTIONS
**/

bool
Ray::initialize(unsigned int pixelX, unsigned int pixelY, Camera* camera)
{
	auto cameraOrigin = camera->getOrigin();
	auto cameraDirection = camera->getDirection();

	this->origin.x = cameraOrigin->x;
	this->origin.y = cameraOrigin->y;
	this->origin.z = cameraOrigin->z;

	this->direction.x = ((2 * pixelX - camera->getViewportWidth()) * tan(camera->getFovX()));
	this->direction.y = ((2 * pixelY - camera->getViewportHeight()) * tan(camera->getFovY()));
	this->direction.z = cameraDirection->z;

	this->normalize(&this->direction);

	return true;
}

sf::Vector3f*
Ray::getOrigin()
{
	return &this->origin;
}

sf::Vector3f*
Ray::getDirection()
{
	return &this->direction;
}