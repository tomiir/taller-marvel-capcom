//
// Created by magali on 01/05/19.
//

#include "ViewController.h"

#include <algorithm> // for heap operations
#include <SDL2/SDL.h>
#include "../../utils/Logger/Logger.h"
#include "../../views/View/View.h"

ViewController::ViewController (SDL_Renderer* renderer_) {
    this->renderer= renderer_;
    this->view = new View(renderer_);
}

