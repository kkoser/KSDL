//
//  ImageView.cpp
//  KSDL
//
//  Created by Kyle Koser on 5/20/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//
//  This class based on CharacterView by Casey Hanley :)

#include "ImageView.h"

ImageView::ImageView( std::string aFileName, SDL_Renderer *aRenderer ) : View({0,0,0,0}, aRenderer), texture(aRenderer) {
    static bool sInitialized = false;
    if (!sInitialized ) {
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            sInitialized = false;
        }
        else {
            printf("Initialized SDL_image");
            sInitialized = true;
        }
    }
    
    textFile = aFileName;
    load();
    
    SDL_Rect imageFrame;
    imageFrame.x = 0;
    imageFrame.y = 0;
    imageFrame.w = texture.getWidth();
    imageFrame.h = texture.getHeight();
    
    View::View( imageFrame, aRenderer );
}

ImageView::ImageView( SDL_Rect aFrame, std::string aFileName, SDL_Renderer *aRenderer) : View(aFrame, aRenderer), texture(aRenderer) {
    static bool sInitialized;
    if (!sInitialized ) {
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            sInitialized = false;
        }
        else {
            printf("Initialized SDL_image");
            sInitialized = true;
        }
    }
    
    textFile = aFileName;
    load();
    
    SDL_Rect imageFrame;
    imageFrame.x = 0;
    imageFrame.y = 0;
    imageFrame.w = texture.getWidth();
    imageFrame.h = texture.getHeight();
    
    View::View( imageFrame, aRenderer );
}

//copy constructor
//fixes issue where strange images show up when copied by forcing the texture to reload
ImageView::ImageView(ImageView const &other) : View(other), texture(other.texture) {
    textFile = other.textFile;
}

ImageView::~ImageView() {
    texture.free();
}

//if the image has not yet been loaded, load it
//lazy loading!
void ImageView::load() {
    if (!(texture.getWidth() > 0)) {
        texture.loadFromFile(textFile);
    }
}

void ImageView::drawInRect(SDL_Rect aRect) {
    View::drawInRect(aRect);

    load();
    // @todo Add support for scaling based on frame size.
    texture.render( aRect.x + frame.x, aRect.y + frame.y, &frame, degs, NULL, flipDir);
    
}

void ImageView::setDegs(double value){
    degs=value;
}
//------------------------------------------------------------------------------
double ImageView::getDegs(){
    return degs;
}
//------------------------------------------------------------------------------
SDL_RendererFlip ImageView::getDir(){
    return flipDir;
}
//------------------------------------------------------------------------------
SDL_RendererFlip ImageView::flipLeft(){
    flipDir=SDL_FLIP_NONE;
    return flipDir;
}
//------------------------------------------------------------------------------
SDL_RendererFlip ImageView::flipRight(){
    flipDir=SDL_FLIP_HORIZONTAL;
    return flipDir;
}