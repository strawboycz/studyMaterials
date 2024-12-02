#include <SDL2/SDL.h>
void line(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Nastavení barvy na černou
        SDL_RenderClear(renderer);                      // Vykreslení pozadí

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Nastavení barvy na červenou
        SDL_RenderDrawLine(renderer, 100, 50, 100, 250); // Vykreslení čáry

        SDL_RenderPresent(renderer);  // Prezentace kreslítka
}