#pragma once

#include "../Headers/tinyxml2.h"

class Decoder
{
		/*	VARIABLES	*/
	
	private:
		Object*	createPlane(tinyxml2::XMLElement* childNode);
		Object*	createLight(tinyxml2::XMLElement* childNode);
		Object*	createSphere(tinyxml2::XMLElement* childNode);
		Object*	createCylinder(tinyxml2::XMLElement* childNode);
		void	recoverColor(tinyxml2::XMLElement* childNode, sf::Color& color);
		void	recoverPosition(tinyxml2::XMLElement* childNode, sf::Vector3f& position);
		void	recoverDirection(tinyxml2::XMLElement* childNode, sf::Vector3f& direction);
		void	recoverRefraction(tinyxml2::XMLElement* childNode, float& refraction);
		void	recoverReflection(tinyxml2::XMLElement* childNode, float& reflection);
		void	recoverRadius(tinyxml2::XMLElement* childNode, float& radius);
protected:
	public:
	
		/*	FUNCTIONS	*/
	
	private:
		void	destroy();
	protected:
	public:
		Decoder();
		~Decoder();
		Decoder(const Decoder& right);
		Decoder&	operator=(const Decoder& right);
	
		std::vector<Object*>*	decrypt();
};