#include "../include/button.hpp"
#include "../SDL2_image/include/SDL_image.h"
#include <iostream>

Button::Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string text_)
{
	colour = { r, g, b, a };
	draw_rect = { x,y,width,height };
	pressed = false;
    text = text_;

}

Button::~Button()
{
    
}

void Button::button_proccess_event(const SDL_Event* ev)
{
    if (ev->type == SDL_MOUSEBUTTONDOWN) {
        if (ev->button.button == SDL_BUTTON_LEFT &&
            ev->button.x >= this->draw_rect.x &&
            ev->button.x <= (this->draw_rect.x +this->draw_rect.w) &&
            ev->button.y >= this->draw_rect.y &&
            ev->button.y <= (this->draw_rect.y + this->draw_rect.h)) {
            this->pressed = true;
        }
    }
}

bool Button::draw_button(SDL_Renderer* renderer, SDL_Window* window) {
    // draw button
    SDL_SetRenderDrawColor(renderer, this->colour.r, this->colour.g, this->colour.b, this->colour.a);
   // SDL_RenderFillRect(r, &this->draw_rect);

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "SDL_IMG for png initialization failed " << IMG_GetError();
    }
    SDL_Surface* surface = IMG_Load("resources/level_select.png");
    SDL_BlitSurface(surface, NULL, window_surface, NULL);



    // if button press detected - reset it so it wouldn't trigger twice
    if (this->pressed) {
        this->pressed = false;
        return true;
    }
    return false;
}