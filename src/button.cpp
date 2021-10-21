#include "../include/button.hpp"
#include "../SDL2_image/include/SDL_image.h"
#include <iostream>

Button::Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string filename)
{
	colour = { r, g, b, a };
	draw_rect = { x,y,width,height };
    pressed = false;
    surface = IMG_Load((filename + ".png").c_str());
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

bool Button::draw_button(SDL_Renderer* renderer, SDL_Surface* window_surface, SDL_Rect* dest_rect) {
    // draw button
   // SDL_SetRenderDrawColor(renderer, this->colour.r, this->colour.g, this->colour.b, this->colour.a);
   // SDL_RenderFillRect(r, &this->draw_rect);


    SDL_BlitSurface(surface, NULL, window_surface, dest_rect);



    // if button press detected - reset it so it wouldn't trigger twice
    if (this->pressed) {
        this->pressed = false;
        return true;
    }
    return false;
}