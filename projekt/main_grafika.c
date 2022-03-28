#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "logika.h"
#include "grafika.h"

int main (int argc, char **argv){

    assert(argc == 3);
    const int C = atoi(argv[1]);
    const int R= atoi(argv[2]);

    int lose = 0;
    int** array;

    array = startGame( R, C, lose);
    int sirka = C*(MEZERA+WIDTH)+ MEZERA+2*START_X;
    int vyska = R*(MEZERA+WIDTH)+ MEZERA+2*START_Y;


    TTF_Init();

    TTF_Font* Sans;
    
    SDL_Texture* Message;
    SDL_Texture* Score;
    SDL_Texture * Score_text;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    }

    SDL_Window* window = SDL_CreateWindow("2048", 400, 150, sirka, vyska, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());

    } else {

      bool quit = false;

      SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (!renderer) {
          SDL_DestroyWindow(window);
          fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
          quit = true;
      }

     


      Sources sources;

      SDL_Event e;

      Nacti_textury(renderer, sources);

      int change = 1;

      while (!quit)
      {
          while (SDL_PollEvent(&e))
          {
            if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
                //User presses a key
                else if( e.type == SDL_KEYDOWN )
                {
                    //Select surfaces based on key press
                    switch( e.key.keysym.sym )
                    {
                        case SDLK_UP:
                        lose = move_up_add(array,R,C);
                        change = 1;
                        break;

                        case SDLK_DOWN:
                        lose = move_down_add(array,R,C);
                        change = 1;
                        break;

                        case SDLK_LEFT:
                        lose = move_left_add(array,R,C);
                        change = 1;
                        break; 

                        case SDLK_RIGHT:
                        lose = move_right_add(array,R,C);
                        change = 1;
                        break;
                    }
                }
            }
            
          

          if (change) {
                change = 0;
                
                Vykresli_hraci_pole(renderer, Sans, Message, Score, Score_text, sources, array, R, C);
                SDL_RenderPresent(renderer);

                if (lose != 0) {
                    if (lose == 1){
                        SDL_Delay(1000);
                        Vykresli_prohru(renderer,Sans, Message);
                        SDL_RenderPresent(renderer);
                        SDL_Delay(5000);
                        quit=true;

                        
                        
                    } else if (lose == 2){
                        SDL_Delay(1000);
                        Vykresli_vyhru(renderer,Sans, Message);
                        SDL_RenderPresent(renderer);
                        SDL_Delay(5000);
                        quit=true;
                    }
                    
                }

          }  
      }

      Uvolni_textury(sources);
     
      SDL_DestroyRenderer(renderer);
      
    }

    uvolni_pamet(array,R);

    SDL_DestroyWindow(window);
    SDL_Quit();

    TTF_Quit();

    return 0;
}