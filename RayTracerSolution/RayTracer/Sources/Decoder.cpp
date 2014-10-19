#include <list>

#include "../Headers/Plane.h"
#include "../Headers/Light.h"
#include "../Headers/Sphere.h"
#include "../Headers/Cylinder.h"
#include "../Headers/Decoder.h"
#include "../Headers/System.h"

/**
* Decoder >> CONTRUCTORS/DESTRUCTOR/INITS
**/

Decoder::Decoder()
{
}

Decoder::Decoder(Decoder const&) //:
{
}

Decoder::~Decoder()
{
	this->destroy();
}

void
Decoder::destroy()
{
}

/**
* Decoder >> OPERATORS
**/

Decoder&
Decoder::operator=(const Decoder&)
{
	return *this;
}

/**
* Decoder >> PRIVATE FUNCTIONS
**/

void
Decoder::recoverRadius(tinyxml2::XMLElement* childNode, float& radius)
{
	auto radiusNode = childNode->NextSiblingElement("Radius");
	radiusNode->QueryFloatText(&radius);
}

void
Decoder::recoverRefraction(tinyxml2::XMLElement* childNode, float& refraction)
{
	auto refractionNode = childNode->NextSiblingElement("Refraction");
	refractionNode->QueryFloatText(&refraction);
}

void
Decoder::recoverReflection(tinyxml2::XMLElement* childNode, float& reflection)
{
	auto reflectionNode = childNode->NextSiblingElement("Reflection");
	reflectionNode->QueryFloatText(&reflection);
}

void
Decoder::recoverColor(tinyxml2::XMLElement* childNode, sf::Color& color)
{
	int red;
	int blue;
	int green;

	auto colorNode = childNode->NextSiblingElement("Color");
	colorNode->FirstChildElement("R")->QueryIntText(&red);
	colorNode->FirstChildElement("G")->QueryIntText(&green);
	colorNode->FirstChildElement("B")->QueryIntText(&blue);
	color = sf::Color((UINT8)red, (UINT8)green, (UINT8)blue);
}

void
Decoder::recoverPosition(tinyxml2::XMLElement* childNode, sf::Vector3f& position)
{
	auto originNode = childNode->NextSiblingElement("Origin");
	originNode->FirstChildElement("X")->QueryFloatText(&position.x);
	originNode->FirstChildElement("Y")->QueryFloatText(&position.y);
	originNode->FirstChildElement("Z")->QueryFloatText(&position.z);
}

void
Decoder::recoverDirection(tinyxml2::XMLElement* childNode, sf::Vector3f& direction)
{
	auto originNode = childNode->NextSiblingElement("Origin");
	originNode->FirstChildElement("X")->QueryFloatText(&direction.x);
	originNode->FirstChildElement("Y")->QueryFloatText(&direction.y);
	originNode->FirstChildElement("Z")->QueryFloatText(&direction.z);
}


Object*
Decoder::createSphere(tinyxml2::XMLElement* childNode)
{
	sf::Color		color;
	float			radius;
	sf::Vector3f	origine;
	float			refraction;
	float			reflection;
	Sphere*			sphere = new Sphere;

	if (!sphere)
		return nullptr;
	this->recoverPosition(childNode, origine);
	this->recoverColor(childNode, color);
	this->recoverRadius(childNode, radius);
	this->recoverRefraction(childNode, refraction);
	this->recoverReflection(childNode, reflection);
	sphere->initialize(origine, color, radius, refraction, reflection);
	return sphere;
}

Object*
Decoder::createPlane(tinyxml2::XMLElement* childNode)
{
	sf::Color		color;
	sf::Vector3f	origine;
	sf::Vector3f	direction;
	float			refraction;
	float			reflection;
	Plane*			plane = new Plane;

	if (!plane)
		return nullptr;
	this->recoverPosition(childNode, origine);
	this->recoverColor(childNode, color);
	this->recoverDirection(childNode, direction);
	this->recoverRefraction(childNode, refraction);
	this->recoverReflection(childNode, reflection);
	plane->initialize(origine, color, direction, refraction, reflection);
	return plane;
}

Object*
Decoder::createCylinder(tinyxml2::XMLElement* childNode)
{
	sf::Color		color;
	float			radius;
	sf::Vector3f	origine;
	sf::Vector3f	direction;
	float			refraction;
	float			reflection;
	Cylinder*		cylinder = new Cylinder;

	if (!cylinder)
		return nullptr;
	this->recoverPosition(childNode, origine);
	this->recoverColor(childNode, color);
	this->recoverDirection(childNode, direction);
	this->recoverRadius(childNode, radius);
	this->recoverRefraction(childNode, refraction);
	this->recoverReflection(childNode, reflection);
	cylinder->initialize(origine, color, direction, radius, refraction, reflection);
	return cylinder;
}

Object*
Decoder::createLight(tinyxml2::XMLElement* childNode)
{
	Light*		light = new Light;

	if (!light)
		return nullptr;
	return light;
}

/**
* Decoder >> PROTECTED FUNCTIONS
**/

/**
* Decoder >> PUBLIC FUNCTIONS
**/

std::vector<Object*>*
Decoder::decrypt()
{
	tinyxml2::XMLDocument xmlDoc;

	xmlDoc.LoadFile("Ressources/Scene_01.xml");
	auto objectNode = xmlDoc.FirstChildElement("Object");
	std::vector<Object*>*	list = new std::vector<Object*>;

	if (!list)
		return nullptr;
	while (objectNode != nullptr)
	{
		auto		childNode = objectNode->FirstChildElement("Type");
		std::string	type(childNode->GetText());
		Object*		object;

		if (type.compare("Sphere") == 0)
			object = this->createSphere(childNode);
		else if (type.compare("Plan") == 0)
			object = this->createPlane(childNode);
		else if (type.compare("Cylinder") == 0)
			object = this->createCylinder(childNode);
		else if (type.compare("Light") == 0)
			object = this->createLight(childNode);
		else
			throw;

		if (!object)
			return nullptr;
		else
			list->push_back(object);
		objectNode = objectNode->NextSiblingElement("Object");
	}
	return list;
}