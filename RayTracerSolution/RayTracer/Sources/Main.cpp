#include "../Headers/System.h"

int CALLBACK WinMain(_In_  HINSTANCE hInstance, _In_  HINSTANCE hPrevInstance, _In_  LPSTR lpCmdLine, _In_  int nCmdShow)
{
	std::unique_ptr<System>	system(new System);

	if (!system)
		return EXIT_FAILURE;
	if (!system->initialize())
		return EXIT_FAILURE;
	system->run();
	system = nullptr;
	return EXIT_SUCCESS;
}