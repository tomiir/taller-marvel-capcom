cmake_minimum_required(VERSION 3.7)
project(taller-marvel-capcom) #DEJAR COMO ESTA. Si no funca ---> renombrar la carpeta donde está el repo de git a esto

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
SET(CMAKE_CXX_FLAGS "-std=c++11")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(
        app main.cpp
        model/Game/Game.cpp model/Game/Game.h
        Clases/TextureManager.cpp Clases/TextureManager.h
        model/GameObjects/GameObject/GameObject.cpp model/GameObjects/GameObject/GameObject.h
        model/GameObjects/Characters/Character/Character.cpp model/GameObjects/Characters/Character/Character.h
        model/GameObjects/Background/Background.cpp model/GameObjects/Background/Background.h
        controllers/Controller/Controller.cpp controllers/Controller/Controller.h
        controllers/ViewController/ViewController.cpp controllers/ViewController/ViewController.h
        views/View/View.cpp views/View/View.h
)
target_link_libraries(app ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
