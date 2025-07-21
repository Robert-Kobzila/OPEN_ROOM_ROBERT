#include <menucontrol.h>
#include <SDL3/SDL.h>
int menucontrol::menu()
{
	const bool* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		return SDL_APP_SUCCESS;
	}
}