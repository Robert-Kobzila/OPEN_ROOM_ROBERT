#pragma once
#include <SDL3/SDL.h>
#include <string>
#include <anim.h>

class player
{
public:
	player(SDL_Renderer* ren,std::string Tpath);
	~player();
	void events();
	void update();
	void initanim(animation animations, int delay, int now,int n);
	void draw();
	SDL_FRect position;
private:
	SDL_Renderer* ren;
	SDL_Texture* texture;
	SDL_FRect rectr, srcr;
	animationdata animations;
	int currentind;
	int lstup;
	float speed;
	float sizesprite;
	int iswalk;
};


