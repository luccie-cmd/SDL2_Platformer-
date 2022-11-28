#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"


void Init(){
    if(SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Sdl_video couldn't init\nError: " << SDL_GetError() << std::endl;
    }
    if(!(IMG_Init(IMG_INIT_PNG))){
        std::cout << "img png couldn't init\nError: " << SDL_GetError() << std::endl;
    }
}

int window_width = 1280;
int window_height = 720;
bool IsRunning = true;
SDL_Event events;

#define _window_width window_width
#define _window_height window_height

int WinMain(int argc, char* argv){
    Init();
    RenderWindow window("Tile", _window_width, _window_height);
    SDL_Texture* bg_Nova = window.LoadTexture("S:/Code/res/gfx/Background_Nova_Lynn.png");
    SDL_Texture* bg = window.LoadTexture("S:/Code/res/gfx/Background.png");
    SDL_Texture* grass = window.LoadTexture("S:/Code/res/gfx/Grass.png");
    int* plat = NULL;
    while(IsRunning){
        while (SDL_PollEvent(&events))
        {
            switch(events.type){
                case SDL_QUIT:
                    IsRunning = false;
                    break;
            }
        }
        window.clear();
        window.RenderBG(bg);
        //window.RenderPlatform(plat);
        window.display();
    }
    window.cleanup();
    SDL_Quit();
    return 0; 
}