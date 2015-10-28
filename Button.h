//
//  Button.h
//  KSDL
//
//  Created by Kyle Koser on 7/19/15.
//  Copyright (c) 2015 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__Button__
#define __KSDL__Button__

#include <stdio.h>

#include "View.h"
#include "TextView.h"

class Button;
class ButtonResponder {
public:
    virtual ~ButtonResponder();
    virtual const void buttonClicked( const Button &button ) = 0;
};

class Button : public View {
//    typedef void (T::*ButtonCallback)(Button *btn);
public:

    Button(SDL_Rect aFrame, SDL_Renderer *aRenderer, std::string title,ButtonResponder &listener);
    
    virtual void handleEvent( SDL_Event e );

private:
    TextView *label;
    ButtonResponder &listener;
};

#endif /* defined(__KSDL__Button__) */
