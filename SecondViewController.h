//
//  SecondViewController.h
//  KSDL
//
//  Created by Kyle Koser on 6/7/15.
//  Copyright (c) 2015 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__SecondViewController__
#define __KSDL__SecondViewController__

#include <stdio.h>

#include "ViewController.h"

class SecondViewController : public ViewController {
public:
    SecondViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame);
    virtual ~SecondViewController();
    
    virtual void handleEvent(SDL_Event e);
};


#endif /* defined(__KSDL__SecondViewController__) */
