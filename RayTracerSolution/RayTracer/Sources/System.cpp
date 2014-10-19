#include "../Headers/System.h"

/**
* System >> CONTRUCTORS/DESTRUCTOR/INITS
**/

System::System() :
window(nullptr),
renderer(nullptr)
{
}

System::System(System const&) //:
{
}

System::~System()
{
	this->destroy();
}

void
System::destroy()
{
	this->window = nullptr;
	this->renderer = nullptr;
}

/**
* System >> OPERATORS
**/

System&
System::operator=(const System&)
{
	return *this;
}

/**
* System >> PRIVATE FUNCTIONS
**/

void
System::calculate()
{
	for (unsigned int height = 0u; height < 600; height++)
	{
		for (unsigned int width = 0u; width < 800; width++)
			this->renderer->setPixel(width, height, sf::Color((UINT8)width, (UINT8)height, (UINT8)width + (UINT8)height));
	}
}

void
System::draw()
{
	sf::Sprite	sprite;
	sf::Texture	texture;

	texture.loadFromImage(*this->renderer);
	sprite.setTexture(texture);

	this->window->clear(sf::Color::Black);
	this->window->draw(sprite);
	this->window->display();
}

/**
* System >> PROTECTED FUNCTIONS
**/

/**
* System >> PUBLIC FUNCTIONS
**/

bool
System::initialize()
{
	unsigned int width = 800u;
	unsigned int height = 600u;
	
	this->window.reset(new sf::RenderWindow(sf::VideoMode(width, height), "TheBestPlatformerInTheWorld"));
	if (!this->window)
		return false;
	this->renderer.reset(new sf::Image);
	if (!this->renderer)
		return false;
	this->renderer->create(width, height, sf::Color::Black);
	this->running = true;
	return true;
}

void
System::run()
{
	this->calculate();
	this->draw();
	while (this->running)
		;
	if (this->window->isOpen())
		this->window->close();
}