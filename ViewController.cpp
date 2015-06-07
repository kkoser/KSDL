//
//  ViewController.cpp
//  FinalFourFearsomeFantasy
//
//  Created by Kyle Koser on 4/8/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include "ViewController.h"
#include <SDL2/SDL.h>

ViewController::ViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame)
: renderer(aRenderer)
{
    view = new View(aFrame, aRenderer);
}

ViewController::~ViewController() {
    // The view will handle deleting all of its subviews.
    delete view;
}

View* ViewController::getView() const {
    return view;
}

SDL_Renderer* ViewController::getRenderer() const {
    return renderer;
}

void ViewController::handleEvent(SDL_Event e) {
    draw(e);
}

void ViewController::draw(SDL_Event e) {
    // @todo remove the need for an empty rect.
    SDL_Rect empty = {0, 0, view->getFrame().h, view->getFrame().w};
    view->drawInRect(empty, e);
}