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
        model/GameObjects/GameObject/GameObject.cpp
        model/GameObjects/GameObject/GameObject.h
        model/GameObjects/Characters/Character/Character.cpp
        model/GameObjects/Characters/Character/Character.h
        model/GameObjects/Background/Background.cpp
        model/GameObjects/Background/Background.h
        controllers/Controller/Controller.cpp
        controllers/Controller/Controller.h
        controllers/ViewController/ViewController.cpp
        controllers/ViewController/ViewController.h
        views/View/View.cpp views/View/View.h
        utils/TextureManager/TextureManager.cpp
        utils/TextureManager/TextureManager.h
        model/Game/ViewControllerFactory/ViewControllerFactory.cpp
        model/Game/ViewControllerFactory/ViewControllerFactory.h
        model/Game/GameObjectControllerFactory/GameObjectControllerFactory.cpp
        model/Game/GameObjectControllerFactory/GameObjectControllerFactory.h
        model/Game/GameObjectFactory/GameObjectFactory.cpp
        model/Game/GameObjectFactory/GameObjectFactory.h
        model/Viewmanager/ViewManager.cpp
        model/Viewmanager/ViewManager.h
        model/Game/ViewControllerFactory/ViewControllerFactory.cpp
        model/Game/ViewControllerFactory/ViewControllerFactory.h
        model/Viewmanager/ViewManager.cpp
        model/Viewmanager/ViewManager.h
        utils/EventToValueMapper/EventToValueMapper.cpp
        utils/EventToValueMapper/EventToValueMapper.h
        controllers/Controller/ControllerCharacter/ControllerCharacter.cpp
        controllers/Controller/ControllerCharacter/ControllerCharacter.h
        controllers/Controller/ControllerBackground/ControllerBackground.cpp
        controllers/Controller/ControllerBackground/ControllerBackground.h
        utils/Vector2D/DirectionVector.cpp
        utils/Vector2D/DirectionVector.h
        Animations/Animation.cpp
        Animations/Animation.h
        utils/SpriteManagers/SpriteManager.h
        utils/SpriteManagers/SpriteManager.cpp
        utils/SpriteManagers/CaptainAmerica/CaptainAmericaSpriteManager.cpp
        utils/SpriteManagers/CaptainAmerica/CaptainAmericaSpriteManager.h
        Animations/CaptainAmerica/CaptainAmericaStillAnimation.cpp
        Animations/CaptainAmerica/CaptainAmericaStillAnimation.h
        Animations/CaptainAmerica/CaptainAmericaWalkFowardAnimation.cpp
        Animations/CaptainAmerica/CaptainAmericaWalkFowardAnimation.h
        Animations/CaptainAmerica/CaptainAmericaCrowchedDownAnimation.cpp
        Animations/CaptainAmerica/CaptainAmericaCrowchedDownAnimation.h
        Animations/CaptainAmerica/CaptainAmericaJumpAnimation.cpp
        Animations/CaptainAmerica/CaptainAmericaJumpAnimation.h
        Animations/CaptainAmerica/CaptainAmericaWalkBackwardsAnimation.cpp
        Animations/CaptainAmerica/CaptainAmericaWalkBackwardsAnimation.h
        Animations/SpiderMan/SpiderManCrowchedDownAnimation.cpp
        Animations/SpiderMan/SpiderManCrowchedDownAnimation.h
        Animations/SpiderMan/SpiderManJumpAnimation.cpp
        Animations/SpiderMan/SpiderManJumpAnimation.h
        Animations/SpiderMan/SpiderManStillAnimation.cpp
        Animations/SpiderMan/SpiderManStillAnimation.h
        Animations/SpiderMan/SpiderManWalkAnimation.cpp
        Animations/SpiderMan/SpiderManWalkAnimation.h
        utils/EventToValueMapper/EventToValueMapper_player1.cpp
        utils/EventToValueMapper/EventToValueMapper_player1.h
        utils/EventToValueMapper/EventToValueMapper_player2.cpp
        utils/EventToValueMapper/EventToValueMapper_player2.h
        utils/TeamManager/TeamManager.cpp
        utils/TeamManager/TeamManager.h
        Animations/Venom/VenomCrowchedDownAnimation.cpp
        Animations/Venom/VenomCrowchedDownAnimation.h
        Animations/Venom/VenomJumpAnimation.cpp
        Animations/Venom/VenomJumpAnimation.h
        Animations/Venom/VenomStillAnimation.cpp
        Animations/Venom/VenomStillAnimation.h
        Animations/Venom/VenomWalkBackwardsAnimation.cpp
        Animations/Venom/VenomWalkBackwardsAnimation.h
        Animations/Venom/VenomWalkFowardAnimation.h
        Animations/Venom/VenomWalkFowardAnimation.cpp
        utils/SpriteManagers/SpiderMan/SpiderManSpriteManager.cpp
        utils/SpriteManagers/SpiderMan/SpiderManSpriteManager.h
        Animations/China/ChinaStillAnimation.cpp Animations/China/ChinaStillAnimation.h
        Animations/China/ChinaWalkAnimation.cpp Animations/China/ChinaWalkAnimation.h
        utils/SpriteManagers/Venom/VenomSpriteManager.cpp utils/SpriteManagers/Venom/VenomSpriteManager.h
        utils/Logger/Logger.cpp utils/Logger/Logger.h)

target_link_libraries(app ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

