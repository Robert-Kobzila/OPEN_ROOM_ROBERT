#include <player.h>
#include <SDL3/SDL_image.h>

void player::update()
{

	const bool* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_W])
	{
		rectr.y -= speed;
	}
	if (keys[SDL_SCANCODE_S])
	{
		rectr.y += speed;
	}
	if (keys[SDL_SCANCODE_D])
	{
		rectr.x += speed;
	}
	if (keys[SDL_SCANCODE_A])
	{
		rectr.x -= speed;
	}
	Uint64 now =SDL_GetTicks();
	int delay = now-lstup;
	if(delay>=idle.animationDelay)
	{ 
		lstup = now;
		currentind++;
		if (idle.frames <= currentind)
		{
			currentind = 0;
		}
		srcr.x = currentind * sizesprite;
	}
}
void player::draw()
{
	SDL_RenderTexture(ren, texture, &srcr, &rectr);
}
void player::events()
{

}
player::player(SDL_Renderer* ren,std::string TPath) : ren(ren)
{
	idle.animationDelay = 100;
	idle.frames = 4;
	idle.x = 0;
	sizesprite = 160;
	texture = IMG_LoadTexture(ren,TPath.c_str());
	rectr = { 100,600,160,160 };
	srcr = { 0,0,160,160 };
	speed = 0.2;
}
player::~player()
{
	SDL_DestroyTexture(texture);
}