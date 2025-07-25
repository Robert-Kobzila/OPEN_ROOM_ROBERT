#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <player.h>
#include <backspace.h>
#include <menucontrol.h>
#include <npc.h>

static SDL_Window* man;
static SDL_Renderer* ren;
player* Player = nullptr;
backspace* Backspace = nullptr;
menucontrol* Menu = nullptr;
npc *NPC=nullptr;
TTF_Font *font;
SDL_AppResult SDL_AppInit(void**appstate,int argc,char*argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_CreateWindowAndRenderer("Prikol", 1000, 1000, 0, &man, &ren);
	Player = new player(ren,"Sprite_BOBIDLE.png");
	Backspace = new backspace(ren,"sun_day.png");
	NPC = new npc(ren, 700, 600, 200, 200, "NPC_GRUSHA.png");
	font = TTF_OpenFont("Caveat.ttf", 70);
	Menu = new menucontrol(ren, 0, 0, 100, 100, "key_e.png",font);
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	const bool* keys = SDL_GetKeyboardState(NULL);
	if (event->type == SDL_EVENT_QUIT)
	{
		return SDL_APP_SUCCESS;
	}
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		return SDL_APP_SUCCESS;
	}
	else {
         return SDL_APP_CONTINUE;
	}
	
	
}
SDL_AppResult SDL_AppIterate(void* appstate)
{
	SDL_RenderClear(ren);
	Backspace->draw();
	NPC->draw();
	NPC->update();
	Player->update();	
	Player->draw();
	Menu->drawkey(Player->position.x, Player->position.y, NPC->position.x, NPC->position.y);
	Menu->drawtext(Player->position.x,Player->position.y);
	SDL_RenderPresent(ren);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
  
}