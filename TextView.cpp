//
//  TextView.cpp
//  KSDL
//
//  Created by Kyle Koser on 8/11/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include "TextView.h"

TextView::TextView(std::string aString, std::string aFontFamily, SDL_Color aColor, int aSize, SDL_Rect aFrame, SDL_Renderer *aRenderer) : View(aFrame, aRenderer), texture(aRenderer), text(aString), textColor(aColor) {
    static bool sInitizlized = false;
    if( !sInitizlized ) {
        if( TTF_Init() == -1 )
        {
            printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            sInitizlized = false;
        }
        else
        {
            sInitizlized = true;
        }
    }
    
    font = TTF_OpenFont(aFontFamily.c_str(), aSize);
    if(font == NULL) printf("font fail: %s\n", TTF_GetError());
    dirty = true;
}

void TextView::drawInRect(SDL_Rect aFrame) {
    View::drawInRect(aFrame);

    // Lazy load the text texture.
    if (dirty) {
        texture.loadFromRenderedText(text, textColor, font);
    }
    texture.render(aFrame.x + getFrame().x, aFrame.y + getFrame().y, &frame);
}

std::string TextView::getText() const {
    return text;
}

SDL_Color TextView::getTextColor() const {
    return textColor;
}

void TextView::setText(std::string aString) {
    text = aString;
    dirty = true;
}

void TextView::setTextColor(SDL_Color aColor) {
    textColor = aColor;
    dirty = true;
}