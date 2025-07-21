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
	texture = IMG_LoadTexture(ren,TPath.c_str());
	rectr = { 100,100,160,160 };
	srcr = { 0,0,160,160 };
	speed = 1;
}
player::~player()
{
	SDL_DestroyTexture(texture);
}