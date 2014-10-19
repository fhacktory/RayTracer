#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "../Headers/Ray.h"

class Object
{
		/*	VARIABLES	*/
	public:
		struct Transform
		{
			float	xAxis = 0;
			float	yAxis = 0;
			float	zAxis = 0;
			float	allAxis = 0;
			float	alignZAxis = 0;
		};
	private:
	protected:
		float			refraction;
		float			reflection;
		Transform		transform;
		sf::Vector3f	origine;
		sf::Color		color;


		/*	FUNCTIONS	*/

	private:
		void	destroy();
	protected:
	public:
		Object();
		~Object();
		Object(const Object& right);
		Object&	operator=(const Object& right);

		virtual void	initialize(sf::Vector3f origine, sf::Color color, float refraction, float reflection);

		double		retMin(double x, double y);
		sf::Color* getColor();
		virtual double intersection(Ray* ray) = 0;
		virtual void	calculateColor() = 0;
};