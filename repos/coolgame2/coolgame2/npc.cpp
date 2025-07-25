#include <npc.h>
#include <SDL3/SDL_image.h>

void npc::draw()
{
	SDL_RenderTexture(ren, texture, &srcr, &rectr);
}
void npc::update()
{
	Uint64 now = SDL_GetTicks();
	int delay = now - lstup;
	if (delay >= animations.idle.animationDelay)
	{
		lstup = now;
		currentind++;
		if (animations.idle.frames <= currentind)
		{
			currentind = 0;
		}
		srcr.x = currentind * sizesprite;
	}
}

npc::npc(SDL_Renderer* ren,float x,float y,float w,float h,std::string TPath):ren(ren)
{
	animations.idle = { 4,250,0,0 };
	sizesprite = 320;
	texture = IMG_LoadTexture(ren, TPath.c_str());
	rectr = { x,y,w,h };
	position = rectr;
	srcr = { 0,0,320,320 };
}
npc::~npc()
{
	SDL_DestroyTexture(texture);
}