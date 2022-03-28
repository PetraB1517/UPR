#pragma once

extern const int MEZERA;
extern const int WIDTH;
extern const int HEIGHT;
extern const int START_X;
extern const int START_Y;
typedef SDL_Texture* Sources[12];

SDL_Texture* loadTexture(char* image, SDL_Renderer *ren);

void Vykresli_hraci_pole (SDL_Renderer *renderer, TTF_Font* Sans, SDL_Texture*Message,SDL_Texture* Score ,SDL_Texture * Score_text, Sources sources, int**array, int R, int C);
void Vykresli_prohru(SDL_Renderer *renderer, TTF_Font* Sans, SDL_Texture*Message);
void Vykresli_vyhru(SDL_Renderer *renderer, TTF_Font* Sans, SDL_Texture*Message);
void Nacti_textury(SDL_Renderer *ren, Sources sources);
void Uvolni_textury(Sources sources); 