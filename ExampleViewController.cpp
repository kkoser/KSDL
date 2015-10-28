//
//  ExampleViewController.cpp
//  KSDL
//
//  Created by Kyle Koser on 8/11/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include "ExampleViewController.h"

#include "TextView.h"
#include "ImageView.h"
#include "Window.h"

#include "SecondViewController.h"

ExampleViewController::ExampleViewController(SDL_Renderer *aRenderer, SDL_Rect aFrame) : ViewController(aRenderer, aFrame) {
    
    Button *btn = new Button({200,200,200,200}, aRenderer, "Button!", *this);
    getView()->addSubview(btn);
}

ExampleViewController::~ExampleViewController()
{
}

const void ExampleViewController::buttonClicked(const Button &button) {
    std::cout<<"Clicked a button!"<<std::endl;
}

