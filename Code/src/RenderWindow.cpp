#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* _title, int _width, int _height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
    if (window == NULL){
        std::cout << "Window could not create\nError: " << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
void RenderWindow::cleanup(){
    SDL_DestroyWindow(window);
}
void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}
void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}
SDL_Renderer* RenderWindow::GetRenderer(){
    return renderer;
}
SDL_Texture* RenderWindow::LoadTexture(const char* _path){
    SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, _path);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}
void RenderWindow::RenderBG(SDL_Texture* _texture){
    SDL_RenderCopy(renderer, _texture, NULL, NULL);
}