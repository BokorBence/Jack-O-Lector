#include "../include/button.hpp"
#include "../SDL2_image/include/SDL_image.h"

Button::Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string filename, SDL_Renderer* renderer, SDL_Surface* window_surface)
{
	colour = { r, g, b, a };
	draw_rect = { x,y,width,height };
    pressed = false;
    surface = IMG_Load((filename + ".png").c_str());
    this->renderer = renderer;
    this->window_surface = window_surface;
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

bool Button::draw_button() {


    SDL_BlitSurface(surface, NULL, window_surface, &draw_rect);

    return false;
}