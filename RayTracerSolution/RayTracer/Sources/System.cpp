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
System::parseSphere(tinyxml2::XMLElement* childNode)
{
	int originX;
	int originY;
	int originZ;

	int colorR;
	int colorG;
	int colorB;

	int radius;

	int refraction;
	int reflection;

	auto originNode = childNode->NextSiblingElement("Origin");
	originNode->FirstChildElement("X")->QueryIntText(&originX);
	originNode->FirstChildElement("Y")->QueryIntText(&originY);
	originNode->FirstChildElement("Z")->QueryIntText(&originZ);

	auto colorNode = childNode->NextSiblingElement("Color");
	colorNode->FirstChildElement("R")->QueryIntText(&colorR);
	colorNode->FirstChildElement("G")->QueryIntText(&colorG);
	colorNode->FirstChildElement("B")->QueryIntText(&colorB);

	auto radiusNode = childNode->NextSiblingElement("Radius");
	radiusNode->QueryIntText(&radius);

	auto refractionNode = childNode->NextSiblingElement("Refraction");
	refractionNode->QueryIntText(&refraction);

	auto reflectionNode = childNode->NextSiblingElement("Reflection");
	reflectionNode->QueryIntText(&reflection);
}

void
System::parsePlan(tinyxml2::XMLElement* childNode)
{
	int originX;
	int originY;
	int originZ;

	int colorR;
	int colorG;
	int colorB;

	int dirX;
	int dirY;
	int dirZ;

	int refraction;
	int reflection;

	auto originNode = childNode->NextSiblingElement("Origin");
	originNode->FirstChildElement("X")->QueryIntText(&originX);
	originNode->FirstChildElement("Y")->QueryIntText(&originY);
	originNode->FirstChildElement("Z")->QueryIntText(&originZ);

	auto colorNode = childNode->NextSiblingElement("Color");
	colorNode->FirstChildElement("R")->QueryIntText(&colorR);
	colorNode->FirstChildElement("G")->QueryIntText(&colorG);
	colorNode->FirstChildElement("B")->QueryIntText(&colorB);

	auto dirNode = childNode->NextSiblingElement("Direction");
	dirNode->FirstChildElement("X")->QueryIntText(&dirX);
	dirNode->FirstChildElement("Y")->QueryIntText(&dirY);
	dirNode->FirstChildElement("Z")->QueryIntText(&dirZ);

	auto refractionNode = childNode->NextSiblingElement("Refraction");
	refractionNode->QueryIntText(&refraction);

	auto reflectionNode = childNode->NextSiblingElement("Reflection");
	reflectionNode->QueryIntText(&reflection);
}

void
System::parseCylinder(tinyxml2::XMLElement* childNode)
{
	int originX;
	int originY;
	int originZ;

	int colorR;
	int colorG;
	int colorB;

	int dirX;
	int dirY;
	int dirZ;

	int radius;

	int refraction;
	int reflection;

	auto originNode = childNode->NextSiblingElement("Origin");
	originNode->FirstChildElement("X")->QueryIntText(&originX);
	originNode->FirstChildElement("Y")->QueryIntText(&originY);
	originNode->FirstChildElement("Z")->QueryIntText(&originZ);

	auto colorNode = childNode->NextSiblingElement("Color");
	colorNode->FirstChildElement("R")->QueryIntText(&colorR);
	colorNode->FirstChildElement("G")->QueryIntText(&colorG);
	colorNode->FirstChildElement("B")->QueryIntText(&colorB);

	auto dirNode = childNode->NextSiblingElement("Direction");
	dirNode->FirstChildElement("X")->QueryIntText(&dirX);
	dirNode->FirstChildElement("Y")->QueryIntText(&dirY);
	dirNode->FirstChildElement("Z")->QueryIntText(&dirZ);

	auto radiusNode = childNode->NextSiblingElement("Radius");
	radiusNode->QueryIntText(&radius);

	auto refractionNode = childNode->NextSiblingElement("Refraction");
	refractionNode->QueryIntText(&refraction);

	auto reflectionNode = childNode->NextSiblingElement("Reflection");
	reflectionNode->QueryIntText(&reflection);
}

void
System::parseLight(tinyxml2::XMLElement* childNode)
{

}

void
System::parseFile()
{
	tinyxml2::XMLDocument xmlDoc;

	xmlDoc.LoadFile("Ressources/Scene_01.xml");
	auto objectNode = xmlDoc.FirstChildElement("Object");

	while (objectNode != nullptr)
	{
		auto childNode = objectNode->FirstChildElement("Type");

		std::string type(childNode->GetText());

		if (type.compare("Sphere") == 0)
			this->parseSphere(childNode);
		else if (type.compare("Plan") == 0)
			this->parsePlan(childNode);
		else if (type.compare("Cylinder") == 0)
			this->parseCylinder(childNode);
		else if (type.compare("Light") == 0)
			this->parseLight(childNode);
		else
			throw;

		objectNode = objectNode->NextSiblingElement("Object");
	}
}

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
	
	this->parseFile();
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