#pragma once

class Decoder
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
	Decoder();
	~Decoder();
	Decoder(const Decoder& right);
	Decoder&	operator=(const Decoder& right);

	void	decrypt();
};