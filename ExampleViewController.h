//
//  ExampleViewController.h
//  KSDL
//
//  Created by Kyle Koser on 8/11/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__ExampleViewController__
#define __KSDL__ExampleViewController__

#include <iostream>

#include "ViewController.h"

class ExampleViewController : public ViewController {
public:
    ExampleViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame);
    virtual ~ExampleViewController();
    
    virtual void handleEvent(SDL_Event e);
};

#endif /* defined(__KSDL__ExampleViewController__) */
