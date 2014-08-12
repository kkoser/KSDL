//
//  Window.h
//  KSDL
//
//  Created by Kyle Koser on 8/5/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__Window__
#define __KSDL__Window__

#include <SDl2/SDL.h>

#include "ViewController.h"

class Window {
public:
    Window( const char *title, int aX, int aY, int aHeight, int aWidth, Uint32 aFlags );
    virtual ~Window();
    
    SDL_Renderer* getRenderer();
    ViewController* getRootViewController();
    
    void run();
    
    void setRootViewController(ViewController *aViewController);
    
private:
    SDL_Renderer *renderer;
    ViewController *rootViewController;
    SDL_Window *window;
};

#endif /* defined(__KSDL__Window__) */