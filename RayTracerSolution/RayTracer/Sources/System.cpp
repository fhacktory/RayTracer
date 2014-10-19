#include <list>

#include "../Headers/Object.h"
#include "../Headers/System.h"
#include "../Headers/Decoder.h"

/**
* System >> CONTRUCTORS/DESTRUCTOR/INITS
**/

System::System() :
camera(nullptr),
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
	this->camera = nullptr;
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
System::manageEvents()
{
	sf::Event	event;

	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->running = false;
	}
}

sf::Color*
System::seekIntersection(std::vector<Object*>* objectList, Ray* ray)
{
	sf::Color* ret = new sf::Color(0, 0, 0);
	double min = 0.0f;

	for (int i = 0; i < objectList->size(); ++i)
	{
		double det = (*objectList)[i]->intersection(ray);
		if (det > 0.0f && (!min || min > det))
		{
			min = det;
			ret = (*objectList)[i]->getColor();
		}
	}

	return ret;
}

bool
System::compute(unsigned int width, unsigned int height)
{
	Decoder	decoder;
	std::vector<Object*>*	objectsList;

	objectsList = decoder.decrypt();
	if (!objectsList)
		return false;
	//raycast
	for (unsigned int x = 0u; x < width; x++)
	{
		for (unsigned int y = 0u; y < height; y++)
		{
			std::unique_ptr<Ray> ray(new Ray);

			ray->initialize(x, y, this->camera.get());
			sf::Color* pixelColor = this->seekIntersection(objectsList, ray.get());
			this->renderer->setPixel(x, y, *pixelColor);
		}
	}
	return true;
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
	unsigned int width = 1280u;
	unsigned int height = 720u;
	
	this->camera.reset(new Camera);
	if (!this->camera)
		return false;
	this->camera->initialize(width, height);
	this->window.reset(new sf::RenderWindow(sf::VideoMode(width, height), "fHACKtory 2014 - RayTracer"));
	if (!this->window)
		return false;
	this->renderer.reset(new sf::Image);
	if (!this->renderer)
		return false;
	this->renderer->create(width, height, sf::Color::Black);
	this->running = true;
	return true;
}

bool
System::run()
{
	if (!this->compute(this->camera->getViewportWidth(), this->camera->getViewportHeight()))
		return false;
	this->draw();
	while (this->running)
		this->manageEvents();
	if (this->window->isOpen())
		this->window->close();
	return true;
}