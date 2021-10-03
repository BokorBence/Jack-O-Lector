#include "../include/button.hpp"

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

bool Button::buttonPressed(SDL_Renderer* r) {
    // draw button
    SDL_SetRenderDrawColor(r, this->colour.r, this->colour.g, this->colour.b, this->colour.a);
    SDL_RenderFillRect(r, &this->draw_rect);

    // if button press detected - reset it so it wouldn't trigger twice
    if (this->pressed) {
        this->pressed = false;
        return true;
    }
    return false;
}