//
//  main.cpp
//  KSDL
//
//  Created by Kyle Koser on 5/20/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#include <iostream>

#include "ExampleViewController.h"
#include "Window.h"

int main(int argc, const char * argv[])
{    
    Window win("Test", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
    ExampleViewController *vc = new ExampleViewController(win.getRenderer(), {0, 0, 500, 500} );
    win.setRootViewController(vc);
    win.run();
    return 0;
}

