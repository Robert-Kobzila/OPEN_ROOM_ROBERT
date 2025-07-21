#include <backspace.h>
#include <SDL3/SDL_image.h>

backspace::backspace(SDL_Renderer* ren,std::string TPath) : ren(ren)
{
	texture = IMG_LoadTexture(ren,TPath.c_str());
	rectr = { 0,0,1000,1000 };
	srcr = { 0,0,1280,1280 };
}
backspace::~backspace()
{
	SDL_DestroyTexture(texture);
}
void backspace::draw()
{
	SDL_RenderTexture(ren, texture, &srcr, &rectr);
}