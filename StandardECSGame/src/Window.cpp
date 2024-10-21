#include "Window.h"

Window window;

Window::Window() : _window(NULL), _renderer(NULL) {

}

Window::~Window() {

}

bool Window::tryCreateWindow() {
    _window = SDL_CreateWindow(
        "", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    if (_window == NULL) {
        std::cout << "Could not create SDL window! Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == NULL) {
        std::cout << "Could not create SDL renderer! Error: " << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

    return true;
}

void Window::setWindowTitle(const char* windowName) {
    SDL_SetWindowTitle(_window, windowName);
}

void Window::clearRenderer() {
    SDL_RenderClear(_renderer);
}

void Window::updateRenderer() {
    SDL_RenderPresent(_renderer);
    SDL_UpdateWindowSurface(_window);
}

void Window::destroyWindow() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}