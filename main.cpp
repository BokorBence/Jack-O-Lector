#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include "include/button.hpp"
#include "include/game.hpp"
#include "include/walkingEntity.hpp"
#include "include/guard.hpp"
#include "include/main_menu_scene.hpp"
#include "include/level_select_menu_scene.hpp"
#include "include/game_scene.hpp"
#include "include/game_over_scene.hpp"
#include <stack>

int main(int argc, char* argv[]) {
    int quit = 0;
    std::stack<Scene*> scenes;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jack O'Lector", 350, 150, 800, 608, SDL_WINDOW_SHOWN);

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
    

    Main_menu_scene main_menu(renderer, &quit, NULL);
    Game_over_scene victory(renderer, &quit, true);
    Game_over_scene defeat(renderer, &quit, false);
    Game_scene game(renderer, &victory,&defeat);
    Level_select_menu_scene level_select_menu(renderer, &main_menu, &game);



    scenes.push(&game);
    scenes.push(&level_select_menu);
    scenes.push(&main_menu);

    Uint32 frameTime, frameStart;
    const Uint32 frameDelay = 17;
    SDL_Event evt;

    //game.g_logic->gameloop(true);

    
    while (!quit)
    {
        //achieving constant framerate
        frameStart = SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        

        // event loop and draw loop are separate things, don't mix them
        while (SDL_PollEvent(&evt)) {
            // quit on close, window close, or 'escape' key hit
            if (evt.type == SDL_QUIT ||
                (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_CLOSE) ||
                (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE)) {
                quit = 1;
            }

            scenes.top()->handle_events(evt);  
        }

        if (scenes.top()->needs_to_be_popped)
        {
            scenes.top()->needs_to_be_popped = false;
            scenes.pop();
        }
        else if (scenes.top()->push_over_me != NULL)
        {
            Scene* next = scenes.top()->push_over_me;
            scenes.top()->push_over_me = NULL;
            scenes.push(next);
        }

        scenes.top()->draw_scene();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
       
         SDL_RenderPresent(renderer);
    }
    

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}