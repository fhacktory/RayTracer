#pragma once

class Object
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
		Object();
		~Object();
		Object(const Object& right);
		Object	operator=(const Object& right);

		bool	initialize();
};