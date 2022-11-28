#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class RenderWindow {
    public:
        RenderWindow(const char* _title, int _width, int _height);
        void cleanup();
        void clear();
        void RenderBG(SDL_Texture* _texture);
        //void RenderPlatform(Platform _platform);
        void display();
        SDL_Renderer* GetRenderer();
        SDL_Texture* LoadTexture(const char* _path);
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};