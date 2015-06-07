//
//  ExampleViewController.cpp
//  KSDL
//
//  Created by Kyle Koser on 8/11/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include "ExampleViewController.h"

#include "TextView.h"

ExampleViewController::ExampleViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame) : ViewController(aRenderer, aFrame) {
    TextView *text = new TextView("Hello World!", "/Library/Fonts/Arial.ttf", {255,0,0}, 40, {150, 200, 300, 100}, aRenderer);
    getView()->addSubview(text);
    View *aView = new View({0,0,100,100}, aRenderer);
    aView->setBackgroundColor({0,0,255,0});
    getView()->addSubview(aView);
}

ExampleViewController::~ExampleViewController()
{
}