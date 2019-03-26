//
// Created by fer on 25/03/19.
//

#include "Game.h"
#include "TextureManager.h"

SDL_Texture* characterText = nullptr;
SDL_Texture* skyText = nullptr;
SDL_Texture* buildingsText = nullptr;
SDL_Texture* streetText = nullptr;

SDL_Rect charRect;


int moveSpeed = 10;


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

        characterText = TextureManager::LoadTexture("/home/fer/Escritorio/taller-marvel-capcom/macriIzq.png", renderer);
        if(!characterText) isRunning = false;
        skyText = TextureManager::LoadTexture("/home/fer/Escritorio/taller-marvel-capcom/Sky.png", renderer);
        if(!skyText) isRunning = false;
        buildingsText = TextureManager::LoadTexture("/home/fer/Escritorio/taller-marvel-capcom/Buildings.png", renderer);
        if(!buildingsText) isRunning = false;
        streetText = TextureManager::LoadTexture("/home/fer/Escritorio/taller-marvel-capcom/Street.png", renderer);
        if(!streetText) isRunning = false;

        charRect.h = 120;
        charRect.w = 60;
        charRect.x = 400;
        charRect.y = 300;

    } else
        {
            std::cout << "Fallo la inicializacion" << std::endl;
            isRunning = false;
        }
}

void Game::render()
{
    SDL_RenderClear(renderer); //Limpiamos el framebuffer (lo que tengamos en pantalla)

    SDL_RenderCopy(renderer, skyText, nullptr, nullptr);
    SDL_RenderCopy(renderer, buildingsText, nullptr, nullptr);
    SDL_RenderCopy(renderer, streetText, nullptr, nullptr);
    SDL_RenderCopy(renderer, characterText, nullptr, &charRect);

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
                    charRect.x += moveSpeed;
                    break;
                case SDLK_LEFT:
                    charRect.x -= moveSpeed;
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


