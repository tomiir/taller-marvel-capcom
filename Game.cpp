//
// Created by fer on 25/03/19.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"


int moveSpeed = 10;

GameObject* character;
GameObject* sky;
GameObject* street;
GameObject* buildings;

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int posX, int posY, int width, int height) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, posX, posY, width, height, SDL_WINDOW_SHOWN);

        if (!window)
        {
            std::cout << "Fallo la creacion de la ventana" << std::endl;
        } else
            {
                renderer = SDL_CreateRenderer(window, -1, 0);

                if (!renderer)
                {
                    std::cout << "Fallo la creacion del render" << std::endl;

                } else
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    }
            }
        isRunning = true;

        character = new GameObject("/home/fer/Escritorio/taller-marvel-capcom/macriIzq.png", renderer, 400, 300, 60, 120);
        if(!character) isRunning = false;

        sky = new GameObject("/home/fer/Escritorio/taller-marvel-capcom/Sky.png", renderer, 0, 0, 800, 600);
        if(!sky) isRunning = false;

        buildings = new GameObject("/home/fer/Escritorio/taller-marvel-capcom/Buildings.png", renderer, 0, 0, 800, 600);
        if(!buildings) isRunning = false;

        street = new GameObject("/home/fer/Escritorio/taller-marvel-capcom/Street.png", renderer, 0, 0, 800, 600);
        if(!street) isRunning = false;


    } else
        {
            std::cout << "Fallo la inicializacion" << std::endl;
            isRunning = false;
        }
}

void Game::render()
{
    SDL_RenderClear(renderer); //Limpiamos el framebuffer (lo que tengamos en pantalla)

    sky->render();
    buildings->render();
    street->render();
    character->render();

    SDL_RenderPresent(renderer); //presenta las cosas en la pantalla.

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    character->move(moveSpeed);
                    break;
                case SDLK_LEFT:
                    character->move(-moveSpeed);
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

void Game::update()
{

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}


