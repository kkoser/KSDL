//
//  View.h
//  KSDL
//
//  Created by Kyle Koser on 5/20/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__View__
#define __KSDL__View__

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "IResponder.h"

using namespace std;

class View : IResponder {
public:
    View(SDL_Rect aFrame, SDL_Renderer *aRenderer);
    virtual ~View();
    void addSubview(View *v, int index = 0);
    
    virtual void drawInRect( SDL_Rect aRect, SDL_Event e );
    
    SDL_Renderer* getRenderer() const;
    SDL_Rect getFrame() const;
    
    virtual void handleEvent( SDL_Event e );
    
    void setFrame( SDL_Rect aFrame );
    void setRenderer( SDL_Renderer *aRenderer );
    
protected:
    SDL_Rect frame = {};
    SDL_Renderer *renderer;
    
private:
    vector<View *> subviews;
};

#endif /* defined(__KSDL__View__) */
