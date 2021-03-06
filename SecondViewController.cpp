//
//  SecondViewController.cpp
//  KSDL
//
//  Created by Kyle Koser on 6/7/15.
//  Copyright (c) 2015 Kyle Koser. All rights reserved.
//

#include "SecondViewController.h"

#include "TextView.h"
#include "ImageView.h"

#include "Window.h"

SecondViewController::SecondViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame) : ViewController(aRenderer, aFrame) {
    TextView *text = new TextView("Second View Controller", "/Library/Fonts/Arial.ttf", {255,0,0}, 40, aFrame, aRenderer);
    getView()->addSubview(text);
}

SecondViewController::~SecondViewController()
{
}