//
//  LTexture.h
//  FFFF
//
//  Created by Kyle Koser on 5/20/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//  Special thanks to Casey Hanley for his hard work in this class.
//

#include <SDL2/SDL.h>
#include "SDL2_ttf/SDL_ttf.h"
#include <string>
using namespace std;

#ifndef FFFF_LTexture_h
#define FFFF_LTexture_h

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture(SDL_Renderer *aRenderer);
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( string path );
    
    //Creates image from font string
    bool loadFromRenderedText( string textureText, SDL_Color textColor, TTF_Font *gFont );
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    SDL_Renderer *renderer;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif
