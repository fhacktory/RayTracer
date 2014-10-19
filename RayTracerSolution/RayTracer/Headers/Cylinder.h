#pragma once

#include "../Headers/Object.h"

class Cylinder : public Object
{
		/*	VARIABLES	*/
	
	private:
		float			radius;
		sf::Vector3f	direction;
	protected:
	public:
	
		/*	FUNCTIONS	*/
	
	private:
		void	destroy();
	protected:
	public:
		Cylinder();
		~Cylinder();
		Cylinder(const Cylinder& right);
		Cylinder&	operator=(const Cylinder& right);
	
		void	initialize(sf::Vector3f origine, sf::Color color, sf::Vector3f direction, float radius, float refraction, float reflection);

		void	intersection();
		void	calculateColor();
};