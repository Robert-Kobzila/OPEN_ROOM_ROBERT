#pragma once
#include <SDL3/SDL.h>
#include <string>
class player
{
public:
	player(SDL_Renderer* ren,std::string Tpath);
	~player();
	void events();
	void update();
	void draw();

private:
	SDL_Renderer* ren;
	SDL_Texture* texture;
	SDL_FRect rectr, srcr;
	float speed;
};


