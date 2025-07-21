#pragma once
#include <SDL3/SDL.h>
#include <string>
class backspace
{
public:
	backspace(SDL_Renderer* ren,std::string TPath);
	void draw();
	~backspace();

private:
	SDL_Renderer* ren;
	SDL_Texture* texture;
	SDL_FRect rectr, srcr;
};