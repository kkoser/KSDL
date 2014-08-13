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
}

Window::~Window() {
    delete rootViewController;
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}

ViewController* Window::getRootViewController() {
    return rootViewController;
}

void Window::run() {
    if(rootViewController != NULL) {
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
            
            rootViewController->handleEvent(e);
            
            //Update screen
            SDL_RenderPresent( renderer );
            SDL_Delay(4);
            e = empty;
        }
    }
}

void Window::setRootViewController(ViewController *aViewController) {
    rootViewController = aViewController;
}