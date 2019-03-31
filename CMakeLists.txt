cmake_minimum_required(VERSION 3.7)
project(taller-marvel-capcom) #DEJAR COMO ESTA. Si no funca ---> renombrar la carpeta donde está el repo de git a esto

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
SET(CMAKE_CXX_FLAGS "-std=c++11")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(app main.cpp Clases/Game.cpp Clases/Game.h Clases/TextureManager.cpp Clases/TextureManager.h Clases/GameObject.cpp Clases/GameObject.h Clases/Character.cpp Clases/Character.h Clases/Background.cpp Clases/Background.h Clases/Controller.cpp Clases/Controller.h model/Game/ViewFactory/ViewFactory.cpp model/Game/ViewFactory/ViewFactory.h model/Game/GameObjectControllerFactory/GameObjectControllerFactory.cpp model/Game/GameObjectControllerFactory/GameObjectControllerFactory.h model/Game/GameObjectFactory/GameObjectFactory_fight.cpp model/Game/GameObjectFactory/GameObjectFactory_fight.h model/Game/GameObjectFactory/GameObjectFactory.cpp model/Game/GameObjectFactory/GameObjectFactory.h model/Game/GameObjectControllerFactory/GameObjectControllerFactory_fight.cpp model/Game/GameObjectControllerFactory/GameObjectControllerFactory_fight.h Views/view/View.cpp Views/view/View.h)
target_link_libraries(app ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
