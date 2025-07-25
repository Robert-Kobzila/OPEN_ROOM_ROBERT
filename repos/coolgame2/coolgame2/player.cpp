#include <player.h>
#include <SDL3/SDL_image.h>

void player::initanim(animation animations,int delay,int now,int n)
{
if(delay>=animations.animationDelay)
	{ 
		lstup = now;
		currentind = (currentind + 1) % animations.frames;
          srcr.x = currentind * sizesprite;
		  srcr.y = sizesprite * (animations.y+n);
	}
}
void player::update()
{
	iswalk = 0;
	const bool* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_W])
	{	
		rectr.y -= speed;
		iswalk = 2;
	}
	if (keys[SDL_SCANCODE_S])
	{

		rectr.y += speed;
		iswalk = 1;
	}
	if (keys[SDL_SCANCODE_D])
	{

		rectr.x += speed;
		iswalk =1;
	}
	if (keys[SDL_SCANCODE_A])
	{
	
		rectr.x -= speed;
		iswalk = 1;
	}
	Uint64 now =SDL_GetTicks();
	int delay = now-lstup;
	if(iswalk==2)
	{
		initanim(animations.walk, delay, now,1);
	}
	else if (iswalk == 1)
	{
		initanim(animations.walk, delay, now, 0);
	}
	else 
	{
		initanim(animations.idle, delay, now,0);
	}
	
	position = rectr;
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
	animations.idle = { 4,100,0,0};
	animations.walk = { 4,50,0,1 };
	sizesprite = 320;
	texture = IMG_LoadTexture(ren,TPath.c_str());
	rectr = { 100,600,200,200 };
	srcr = { 0,0,320,320 };
	speed = 0.2;
}
player::~player()
{
	SDL_DestroyTexture(texture);
}