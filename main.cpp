#include "SDL.h" 
#include <iostream>
#include "include/button.hpp"

int main(int argc, char* argv[]) {
    int quit = 0;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jack O'Lector", 350, 150, 800, 500, SDL_WINDOW_SHOWN);
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

    SDL_Texture* txt = NULL;

    SDL_Rect rct;
    rct.x = 0;
    rct.y = 0;
    rct.h = 500;
    rct.w = 800;

    // button state - colour and rectangle
    Button start_button(150, 54, 148, 1, 0, 0, 100, 50, "level select");

    enum {
        STATE_IN_MENU,
        STATE_IN_GAME,
    } state = STATE_IN_MENU;

    while (!quit) {
        SDL_Event evt;    // no need for new/delete, stack is fine

        // event loop and draw loop are separate things, don't mix them
        while (SDL_PollEvent(&evt)) {
            // quit on close, window close, or 'escape' key hit
            if (evt.type == SDL_QUIT ||
                (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_CLOSE) ||
                (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE)) {
                quit = 1;
            }

            // pass event to button
            start_button.button_proccess_event(&evt);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //      SDL_RenderCopy(renderer, txt, NULL, &rct);

        if (state == STATE_IN_MENU) {
            if (start_button.draw_button(renderer)) {
                printf("start button pressed\n");
                state = STATE_IN_GAME;   // state change - button will not be drawn anymore
            }
        }
        else if (state == STATE_IN_GAME) {
            /* your game logic */
        }

        SDL_RenderPresent(renderer);
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