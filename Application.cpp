#include "Application.hpp"
#include "helper.cpp"

// somewhat translates to implementing an interface?

// constructor
Application::Application() {
    m_window = SDL_CreateWindow("Shapes",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
    if(!m_window) {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);
    if(!m_window_surface) {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_image = helper::load_surface("resources/test.png");
    if(!m_image) {
        std::cout << "Failed to access image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

// destructor(def not in java)
Application::~Application() {
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

// implementation of methods

// if there is an event to be handled, do something
void Application::update() {
    bool keep_window_open = true;
    while(keep_window_open) {
        while(SDL_PollEvent(&m_window_event) > 0) {
            switch(m_window_event.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                break;
            }
        }
        draw();
    }
}

// updates window ig
void Application::draw() {
    SDL_UpdateWindowSurface(m_window);
    SDL_BlitSurface(m_image, NULL, m_window_surface, NULL);
}