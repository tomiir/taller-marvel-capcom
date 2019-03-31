//
// Created by fer on 25/03/19.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Character.h"
#include "Background.h"


int moveSpeed = 20;

Character* character;
Background* sky;
Background* street;
Background* buildings;

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int posX, int posY, int width, int height) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, posX, posY, width, height, SDL_WINDOW_SHOWN);

        if (!window){

            std::cout << "Fallo la creacion de la ventana" << std::endl;

        } else{
                renderer = SDL_CreateRenderer(window, -1, 0);

                if (!renderer){

                    std::cout << "Fallo la creacion del render" << std::endl;

                }
            }
        isRunning = true;

        character = new Character("/home/fer/Escritorio/taller-marvel-capcom/Images/capComSprites/capCom_walk_1.png", renderer, 400, 300, 50, 120);
        if(!character) isRunning = false;

        sky = new Background("/home/fer/Escritorio/taller-marvel-capcom/Images/Backgrounds/Sky.png", renderer, 0, 0, 800, 600, 10 );
        if(!sky) isRunning = false;

        buildings = new Background("/home/fer/Escritorio/taller-marvel-capcom/Images/Backgrounds/Buildings.png", renderer, 0, 0, 800, 600, 20);
        if(!buildings) isRunning = false;

        street = new Background("/home/fer/Escritorio/taller-marvel-capcom/Images/Backgrounds/Street.png", renderer, 0, 0, 800, 600, 25);
        if(!street) isRunning = false;


    } else{
            std::cout << "Fallo la inicializacion" << std::endl;
            isRunning = false;
        }
}

void Game::render(){

    SDL_RenderClear(renderer); //Limpiamos el framebuffer (lo que tengamos en pantalla)

    sky->render();
    buildings->render();
    street->render();
    character->render();

    SDL_RenderPresent(renderer); //presenta las cosas en la pantalla.

}

void Game::handleEvents(){

    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){

        case SDL_QUIT:
            isRunning = false;
            break;
    }

    if(event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym){

            case SDLK_RIGHT:
                character->move(moveSpeed);
                sky->moveCamera(1);
                buildings->moveCamera(1);
                street->moveCamera(1);
                break;
            case SDLK_LEFT:
                character->move(-moveSpeed);
                sky->moveCamera(-1);
                buildings->moveCamera(-1);
                street->moveCamera(-1);
                break;
            case SDLK_UP:
                character->jump();
                break;
            case SDLK_DOWN:
                character->down();
                break;
            default:
                break;
        }
    }
    if(event.type == SDL_KEYUP){

        switch (event.key.keysym.sym){

                case SDLK_DOWN:
                    character->jump();
                    break;
                case SDLK_UP:
                    character->down();
                    break;
                default:
                    break;
            }
    }
}

void Game::update(){

}

void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}


