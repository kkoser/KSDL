//
//  ViewController.h
//  FinalFourFearsomeFantasy
//
//  Created by Kyle Koser on 4/8/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __FinalFourFearsomeFantasy__ViewController__
#define __FinalFourFearsomeFantasy__ViewController__

#include <iostream>
#include <SDL2/SDL.h>

#include "IResponder.h"
#include "View.h"

// Forward Declaration so subclasses can access the window to modify ViewController stack
class Window;

class ViewController : IResponder {
public:
    ViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame);
    
    virtual ~ViewController();
    
    View* getView() const;
    SDL_Renderer* getRenderer() const;
    Window* getWindow() const;
    
    virtual void handleEvent(SDL_Event e);
    
    //the main method of the viewcontroller
    virtual void draw();
    
    // This method only for use by the Window Class
    void setWindow(Window *aWindow);
private:
    SDL_Renderer *renderer;
    View *view;
    Window *window;
};

#endif /* defined(__FinalFourFearsomeFantasy__ViewController__) */
