//
//  Window.cpp
//  KSDL
//
//  Created by Kyle Koser on 8/5/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include "Window.h"

Window::Window( const char *title, int aX, int aY, int aHeight, int aWidth, Uint32 aFlags ) {
    static bool sInitialized = false;
    if( !sInitialized ) {
        if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
        {
            printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            printf("initialized SDL");
            //Set texture filtering to linear
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            {
                printf( "Warning: Linear texture filtering not enabled!" );
            }
            else {
                printf("Intiitlaized texture filtering");
                sInitialized = true;
            }
        }
    }
    
    window = SDL_CreateWindow(title, aX, aY, aHeight, aWidth, aFlags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    printf("created renderer with error: %s\n", SDL_GetError() );
    
    SDL_Surface *winSurface = SDL_GetWindowSurface(window);
    SDL_SetSurfaceBlendMode(winSurface, SDL_BLENDMODE_MOD);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(winSurface);
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}

ViewController* Window::getRootViewController() {
    return viewControllerStack.top();
}

void Window::run() {
    if (viewControllerStack.empty()) {
        return;
    }
    ViewController *vc = viewControllerStack.top();
    if(vc != NULL) {
        SDL_Event e;
        SDL_Event empty; // Needed to clear the event
        bool running = true;

        while( running )
        {
            // Handle events on queue
            SDL_PollEvent( &e );
            
            // Check for quit.
            if( e.type == SDL_QUIT )
            {
                running = false;
            }
            
            vc->handleEvent(e);
            
            //Update screen
            SDL_RenderPresent( renderer );
            SDL_Delay(4);
            e = empty;
        }
    }
}

// This method clears the current ViewController stack and then pushes the given
// ViewController onto the bottom of that stack
// NOTE: This method will destroy the current ViewController stack
void Window::setRootViewController(ViewController *aViewController) {
    viewControllerStack = std::stack<ViewController *>();
    viewControllerStack.push(aViewController);
    aViewController->setWindow(this);
}

void Window::pushViewController(ViewController *aViewController) {
    viewControllerStack.push(aViewController);
    aViewController->setWindow(this);
}

// Removes the top ViewController from the navigation stack
// The top ViewController will be destroyed and deallocated
void Window::popViewController() {
    ViewController *vc = viewControllerStack.top();
    viewControllerStack.pop();
    delete vc;
}