#include <menucontrol.h>

menucontrol::menucontrol(SDL_Renderer* ren, float x, float y, float w, float h, std::string TPath, TTF_Font* font) : ren(ren), font(font)
{
	texture = IMG_LoadTexture(ren, TPath.c_str());
	rectr = { x,y,w,h };
	srcr = { 0,0,160,160 };
	
	
}
void menucontrol::drawtext(float x,float y)
{
	desttext = { x+50,y-100 ,200,100 };
	text = std::to_string(x);
	surftext= TTF_RenderText_Solid(font, text.c_str(),strlen(text.c_str()), color);
	texttexture = SDL_CreateTextureFromSurface(ren,surftext);
	SDL_DestroySurface(surftext);
	SDL_RenderTexture(ren, texttexture, NULL, &desttext);
	SDL_DestroyTexture(texttexture);
}
void menucontrol::drawkey(float x,float y,float xobj,float yobj)
{
	if ((x >= xobj-100 && x <= xobj+100) && (y >= yobj-100 && y <= yobj+100))
	{
      SDL_RenderTexture(ren,texture,&srcr,&rectr);
	}
	
	
}
menucontrol::~menucontrol()
{
	SDL_DestroyTexture(texture);
}
 