#include "../include/button.hpp"
#include "SDL_image.h"

Button::Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string filename, SDL_Renderer* renderer)
{
	colour = { r, g, b, a };
	draw_rect = { x,y,width,height };
    pressed = false;
    surface = IMG_Load((filename).c_str());
    button_tex = SDL_CreateTextureFromSurface(renderer, surface);
    this->renderer = renderer;
}

Button::~Button()
{
    
}

void Button::button_proccess_event(const SDL_Event &ev)
{
    if (ev.type == SDL_MOUSEBUTTONDOWN) {
        if (ev.button.button == SDL_BUTTON_LEFT &&
            ev.button.x >= this->draw_rect.x &&
            ev.button.x <= (this->draw_rect.x +this->draw_rect.w) &&
            ev.button.y >= this->draw_rect.y &&
            ev.button.y <= (this->draw_rect.y + this->draw_rect.h))
        {
            this->pressed = true;
        }
    }
}

void Button::draw_button() {


    SDL_RenderCopy(renderer, button_tex, NULL, &draw_rect);
}