#pragma once
#include "SDL.h"
#include <string>


class Button
{   
    public:
        SDL_Rect draw_rect;
        struct { int r, g, b, a;} colour;
        std::string text;
        void button_proccess_event(const SDL_Event &ev);
        void draw_button();
        Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string filename, SDL_Renderer* renderer);
        ~Button();
        bool pressed;
    private:
        SDL_Surface* surface;
        SDL_Surface* window_surface;
        SDL_Renderer* renderer;
        SDL_Texture* button_tex;

};