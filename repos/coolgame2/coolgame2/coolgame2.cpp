#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{


    SDL_Window* window = SDL_CreateWindow("Prikol", 1000, 1000, 0);
    SDL_Event event;
    SDL_Renderer* ren = SDL_CreateRenderer(window, 0);
    SDL_Texture* text = IMG_LoadTexture(ren, "sun_day.png");
    SDL_Texture* player = IMG_LoadTexture(ren, "BOB_IDLE1.png");
    SDL_FRect rect_player = { 100,600,320,320 };
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_RenderTexture(ren, text, NULL, NULL);
    SDL_RenderTexture(ren, player, NULL, &rect_player);
    SDL_RenderPresent(ren);
    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = 0;
            }
            if (event.key.type == SDL_EVENT_KEY_DOWN) {
                cout(event.key.key);




            }



        }
        SDL_DestroyTexture(player);
        SDL_DestroyTexture(text);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
}
