#pragma once
typedef struct
{
	int frames;
	int animationDelay;
	int x;
	int y;
} animation;

typedef struct
{
	animation idle;
	animation walk;
}animationdata;