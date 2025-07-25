#pragma once
#include <anim.h>
#include <SDL3/SDL.h>
#include <string>

class npc
{
public:
	npc(SDL_Renderer* ren,float x,float y, float w, float h,std::string Tpath);
	~npc();
	void events();
	void update();
	void draw();
	SDL_FRect position;
private:
	SDL_Renderer* ren;
	SDL_Texture* texture;
	SDL_FRect rectr, srcr;
	animationdata animations;
	int currentind;
	int lstup;
	float sizesprite;
};