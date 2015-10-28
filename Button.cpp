//
//  Button.cpp
//  KSDL
//
//  Created by Kyle Koser on 7/19/15.
//  Copyright (c) 2015 Kyle Koser. All rights reserved.
//

#include "Button.h"

Button::Button(SDL_Rect aFrame, SDL_Renderer *aRenderer, std::string aTitle, ButtonResponder &aListener) : View(aFrame, aRenderer), listener(aListener) {
    label = new TextView(aTitle, "/Library/Fonts/Arial.ttf", {255,0,0}, 40, {0,0,100,100}, aRenderer);
    addSubview(label);
}

void Button::handleEvent(SDL_Event e) {
    // Call super
    View::handleEvent(e);
    if (e.type != SDL_MOUSEBUTTONDOWN) {
        return;
    }
    
    // Check if the click is inside the frame
    int x, y;
    SDL_GetMouseState( &x, &y );
    SDL_Rect rect = getFrame();
    if (rect.x < x && (rect.x + rect.w) > x && rect.y < y && (rect.y + rect.h) > y) {
        listener.buttonClicked(*this);
    }
}

ButtonResponder::~ButtonResponder() {
}