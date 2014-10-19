#pragma once

#include <memory>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "../Headers/Ray.h"
#include "../Headers/Object.h"

class System
{
		/*	VARIABLES	*/
	
	private:
		std::unique_ptr<Camera>				camera;
		std::unique_ptr<sf::RenderWindow>	window;
		std::unique_ptr<sf::Image>			renderer;
		bool								running;
	protected:
	public:
	
		/*	FUNCTIONS	*/
	
	private:
		void	destroy();
		
		sf::Color*	seekIntersection(std::vector<Object*>* objectList, Ray* ray);
		void	manageEvents();
		bool	compute(unsigned int width, unsigned int height);
		void	draw();
	protected:
	public:
		System();
		~System();
		System(const System& right);
		System&	operator=(const System& right);
	
		bool	initialize();
		bool	run();
};