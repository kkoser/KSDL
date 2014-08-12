//
//  TextView.h
//  KSDL
//
//  Created by Kyle Koser on 8/11/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__TextView__
#define __KSDL__TextView__

#include <iostream>

#include "View.h"
#include "LTexture.h"

class TextView : public View {
public:
    TextView( std::string aString, std::string aFontFamily, SDL_Color aColor, int aSize, SDL_Rect aFrame, SDL_Renderer *aRenderer );
    
    void drawInRect(SDL_Rect aFrame, SDL_Event e);
    
    std::string getText() const;
    SDL_Color getTextColor() const;
    
    void setText( std::string aString );
    void setTextColor( SDL_Color aColor );
    
private:
    std::string text;
    SDL_Color textColor;
    LTexture texture;
    TTF_Font *font;
};

#endif /* defined(__KSDL__TextView__) */
