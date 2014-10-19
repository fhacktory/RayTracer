#pragma once

#include "../Headers/Object.h"

class Light : public Object
{
		/*	VARIABLES	*/
	
	private:
	protected:
	public:
	
		/*	FUNCTIONS	*/
	
	private:
		void	destroy();
	protected:
	public:
		Light();
		~Light();
		Light(const Light& right);
		Light&	operator=(const Light& right);
	
		void	initialize();

		double	intersection(Ray* ray);
		void	calculateColor();
};