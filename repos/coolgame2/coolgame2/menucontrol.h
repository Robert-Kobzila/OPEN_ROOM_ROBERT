#pragma once
#include <SDL3/SDL.h>
#include <string>
#include<SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
class menucontrol
{
public:
	menucontrol(SDL_Renderer* ren, float x, float y, float w, float h, std::string TPath, TTF_Font* font);
	~menucontrol();
	void menu();
	void drawtext(float x,float y);
	void drawkey(float x,float y,float xobj,float yobj);
private:
	SDL_Renderer* ren;
	SDL_Texture* texture,*texttexture;
	SDL_FRect rectr, srcr,desttext;
	std::string text;
	SDL_Color color = { 255,255,255,255 };
	TTF_Font *font;
	SDL_Surface* surftext;
};
