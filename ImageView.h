//
//  ImageView.h
//  KSDL
//
//  Created by Kyle Koser on 5/20/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __FinalFourFearsomeFantasy__ImageView__
#define __FinalFourFearsomeFantasy__ImageView__

#include <iostream>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "LTexture.h"
#include "View.h"
#include <string>

class ImageView : public View {
public:
    //copy constructor to fix image rendering issue
    ImageView( ImageView const &other);
    ImageView( std::string aFileName, SDL_Renderer *aRenderer );
    ImageView( SDL_Rect aFrame, std::string aFileName, SDL_Renderer *aRenderer);
    virtual ~ImageView();
    
    double getDegs();
    SDL_RendererFlip getDir();
    void setDegs(double value);

    SDL_RendererFlip flipRight();
    SDL_RendererFlip flipLeft();
    
    virtual void drawInRect( SDL_Rect aRect, SDL_Event e );
    
private:
    double degs; //degrees of rotation
    SDL_RendererFlip flipDir = SDL_FLIP_NONE;
    
    LTexture texture;
    string textFile;
    
    void load(); //used for lazy loading
    
};

#endif /* defined(__FinalFourFearsomeFantasy__ImageView__) */
