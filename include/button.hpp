#pragma once
#include "../SDL2/include/SDL.h"
#include <string>

class Button
{   
    public:
        SDL_Rect draw_rect;
        struct { int r, g, b, a;} colour;
        std::string text;
        void button_proccess_event(const SDL_Event* ev);
        bool buttonPressed(SDL_Renderer *r);
        Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string text_);
        ~Button();
    private:
        bool pressed;

};