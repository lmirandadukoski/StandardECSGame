#include "AnimationHelper.h"

AnimationComponent helpers::createAnimation(const char* fileName, int index, int frames, int speed) {

    SDL_Texture* txt = helpers::createTexture(fileName);
    SDL_Rect src = { 0, 0, 32, 32 };
    src.y = index * src.h;

    SDL_Rect dst = { 0, 0, 32, 32 };
    SpriteComponent spr = { src, dst, txt };

    AnimationComponent anm = { spr, index, frames, speed };
    return anm;
}
