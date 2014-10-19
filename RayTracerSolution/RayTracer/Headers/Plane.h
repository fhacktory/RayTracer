#pragma once

#include "../Headers/Object.h"

class Plane : public Object
{
	/*	VARIABLES	*/

private:
	sf::Vector3f	direction;
protected:
public:

	/*	FUNCTIONS	*/

private:
	void	destroy();
protected:
public:
	Plane();
	~Plane();
	Plane(const Plane& right);
	Plane&	operator=(const Plane& right);

	void	initialize(sf::Vector3f origine, sf::Color color, sf::Vector3f direction, float refraction, float reflection);

	double	intersection(Ray* ray);
	void	calculateColor();
};