#pragma once

#include "SFML\System.hpp"
#include "../Headers/Camera.h"

class Ray
{
	/*	VARIABLES	*/

private:
	sf::Vector3f	origin;
	sf::Vector3f	direction;
protected:
public:

	/*	FUNCTIONS	*/

private:
	void	destroy();

	void	normalize(sf::Vector3f* vector);
protected:
public:
	Ray();
	~Ray();
	Ray(const Ray& right);
	Ray&	operator=(const Ray& right);

	bool	initialize(unsigned int pixelX, unsigned int pixelY, Camera* camera);
};