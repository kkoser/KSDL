//
//  IResponder.h
//  KSDL
//
//  Created by Kyle Koser on 8/5/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __KSDL__IResponder__
#define __KSDL__IResponder__

#include <SDL2/SDL.h>

class IResponder
{
    public:
        virtual ~IResponder();
        virtual void handleEvent( SDL_Event e ) = 0;
};

#endif /* defined(__KSDL__IResponder__) */
