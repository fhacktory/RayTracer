#pragma once

#include <memory>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "../Headers/tinyxml2.h"

class System
{
		/*	VARIABLES	*/
	
	private:
		std::unique_ptr<sf::RenderWindow>	window;
		std::unique_ptr<sf::Image>			renderer;
		bool								running;
	protected:
	public:
	
		/*	FUNCTIONS	*/
	
	private:
		void	destroy();
		
		void	parseSphere(tinyxml2::XMLElement* childNode);
		void	parsePlan(tinyxml2::XMLElement* childNode);
		void	parseCylinder(tinyxml2::XMLElement* childNode);
		void	parseLight(tinyxml2::XMLElement* childNode);
		void	parseFile();
		void	calculate();
		void	draw();
	protected:
	public:
		System();
		~System();
		System(const System& right);
		System&	operator=(const System& right);
	
		bool	initialize();
		void	run();
};