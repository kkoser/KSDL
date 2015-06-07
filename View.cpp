//
//  View.cpp
//  KSDL
//
//  Created by Kyle Koser on 5/20/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include "View.h"

View::View( SDL_Rect aFrame, SDL_Renderer *aRenderer ) {
    frame = aFrame;
    renderer = aRenderer;
}

View::~View() {
    // delete all of the subViews.
    vector<View *>::iterator iter;
    for (iter = subviews.begin(); iter != subviews.end(); ++iter) {
        delete *iter;
    }
}

void View::addSubview(View *v, int index) {
    v->setRenderer( getRenderer() );
    subviews.insert( subviews.end() - index, v );
}

void View::drawInRect(SDL_Rect aRect) {
    // Draw the view's background
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderFillRect(renderer, &frame);

    vector<View *>::iterator iter;
    SDL_Rect newRect;
    
    //calculate the new rect relative to the rect and this view's frame
    newRect.x = aRect.x + frame.x;
    newRect.y = aRect.y + frame.y;
    newRect.w = frame.w;
    newRect.h = frame.h;
    
    for (iter = subviews.begin(); iter != subviews.end(); ++iter) {
        (*iter)->drawInRect( newRect );
    }
}

SDL_Color View::getBackgroundColor() const {
    return backgroundColor;
}

SDL_Renderer* View::getRenderer() const {
    return renderer;
}

SDL_Rect View::getFrame() const {
    return frame;
}

void View::handleEvent(SDL_Event e) {
    vector<View *>::iterator iter;
    for (iter = subviews.begin(); iter != subviews.end(); ++iter) {
        (*iter)->handleEvent( e );
    }
}

void View::setBackgroundColor(SDL_Color aColor) {
    backgroundColor = aColor;
}

void View::setFrame(SDL_Rect aFrame) {
    frame = aFrame;
}

void View::setRenderer(SDL_Renderer *aRenderer) {
    renderer = aRenderer;
}