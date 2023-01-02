#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"

#define _window_width 1280
#define _window_height 720


void Init(){
    if(SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Sdl_video couldn't init\nError: " << SDL_GetError() << std::endl;
    }
    if(!(IMG_Init(IMG_INIT_PNG))){
        std::cout << "img png couldn't init\nError: " << SDL_GetError() << std::endl;
    }
}

bool IsRunning = true;
SDL_Event events;

int WinMain(int argc, char* argv){
    Init();
    RenderWindow window("Tile", _window_width, _window_height);
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