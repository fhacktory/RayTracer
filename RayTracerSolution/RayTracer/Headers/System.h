#pragma once

#include <memory>
#include <Windows.h>
#include <SFML/Graphics.hpp>

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
		
		void	manageEvents();
		bool	compute();
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