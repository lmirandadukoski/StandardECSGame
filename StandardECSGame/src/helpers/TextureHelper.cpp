#include "TextureHelper.h"

SDL_Texture* helpers::createTexture(const char* fileName) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if (!tempSurface) {
        std::cout << printf("Unable to load image %s! SDL_image Error: %s\n", fileName, IMG_GetError());
        SDL_FreeSurface(tempSurface);
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(window.getRenderer(), tempSurface);
    SDL_FreeSurface(tempSurface);
    if (!texture) {
        printf("Failed to create texture. Error: %s", SDL_GetError());
        return NULL;
    }
    return texture;
}
