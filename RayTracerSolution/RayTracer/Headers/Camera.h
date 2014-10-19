#pragma once

#include "SFML\System.hpp"

class Camera
{
	/*	VARIABLES	*/

private:
	sf::Vector3f	origin;
	sf::Vector3f	direction;
	unsigned int	viewportWidth;
	unsigned int	viewportHeight;
	float			fovX;
	float			fovY;
protected:
public:

	/*	FUNCTIONS	*/

private:
	void	destroy();
protected:
public:
	Camera();
	~Camera();
	Camera(const Camera& right);
	Camera&	operator=(const Camera& right);

	bool	initialize(unsigned int width, unsigned int height);

	sf::Vector3f*	getOrigin();
	sf::Vector3f*	getDirection();
	unsigned int	getViewportWidth();
	unsigned int	getViewportHeight();
	float			getFovX();
	float			getFovY();
};