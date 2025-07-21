#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <player.h>
#include <backspace.h>


static SDL_Window* man;
static SDL_Renderer* ren;
player* Player = nullptr;
backspace* Backspace = nullptr;
SDL_Texture *back;
SDL_AppResult SDL_AppInit(void**appstate,int argc,char*argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("Prikol", 1000, 1000, 0, &man, &ren);
	Player = new player(ren,"Sprite_BOBIDLE.png");
	Backspace = new backspace(ren,"sun_day.png");
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT)
	{
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate)
{
	SDL_RenderClear(ren);
	Backspace->draw();
	Player->update();	
	Player->draw();
	
	SDL_RenderPresent(ren);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
  
}