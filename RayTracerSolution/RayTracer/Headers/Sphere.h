#pragma once

#include "../Headers/Object.h"

class Sphere : public Object
{
		/*	VARIABLES	*/
	
	private:
		float	radius;
	protected:
	public:
	
		/*	FUNCTIONS	*/
	
	private:
		void	destroy();
	protected:
	public:
		Sphere();
		~Sphere();
		Sphere(const Sphere& right);
		Sphere&	operator=(const Sphere& right);
	
		void	initialize(sf::Vector3f origine, sf::Color color, float	radius, float refraction, float reflection);

		void	intersection();
		void	calculateColor();
};