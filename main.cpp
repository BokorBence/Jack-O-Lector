#include "SDL.h" 
#include <iostream>
#include "SDL2_image/include/SDL_image.h"
#include "include/button.hpp"
#include "include/main_menu_scene.hpp"
#include <fstream>
#include <stack>

int main(int argc, char* argv[]) {
    int quit = 0;
    std::stack<Scene*> scenes;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jack O'Lector", 350, 150, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "create window failed: %s\n", SDL_GetError());
        return 1;   // 'error' return status is !0. 1 is good enough
    }

    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {   // renderer creation may fail too
        fprintf(stderr, "create renderer failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "SDL_IMG for png initialization failed " << IMG_GetError();
    }
    Scene* scene;
    Main_menu_scene main_menu;
    scene = &main_menu;
    scenes.push(scene);

    Uint32 frameTime, frameStart;
    const Uint32 frameDelay = 17;

    while (!quit)
    {
        //achieving constant framerate
        frameStart = SDL_GetTicks();
        SDL_RenderClear(renderer);

        SDL_Event evt;    // no need for new/delete, stack is fine

        // event loop and draw loop are separate things, don't mix them
        while (SDL_PollEvent(&evt)) {
            // quit on close, window close, or 'escape' key hit
            if (evt.type == SDL_QUIT ||
                (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_CLOSE) ||
                (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE)) {
                quit = 1;
            }


        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //SDL_RenderClear(renderer);

        //      SDL_RenderCopy(renderer, txt, NULL, &rct);

        scenes.top()->draw_scene(renderer, window_surface);

       
        //std::cout << SDL_GetPerformanceFrequency() << std::endl;
        
        

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
        //SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}

/*int main(int argc, char* argv[])
{
    std::cout << "proba" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}*/

/*
frameStart = SDL_GetTicks();

SDL_RenderClear(m_renderer);




SDL_RenderPresent(m_renderer);


frameTime = SDL_GetTicks() - frameStart;

if (frameDelay > frameTime) {
    SDL_Delay(frameDelay - frameTime);
}

*/