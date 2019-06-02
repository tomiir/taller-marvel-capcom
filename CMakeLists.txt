cmake_minimum_required(VERSION 3.7)
project(taller-marvel-capcom) #DEJAR COMO ESTA. Si no funca ---> renombrar la carpeta donde está el repo de git a esto

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -lstdc++ -lm -ldl")
set(CMAKE_CXX_STANDARD_LIBRARIES -ljsoncpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${JSON_INC_PATH})

add_executable(
        app main.cpp
        Json/JsonBackground.h
        Json/JsonBackground.cpp
        Json/JsonCharacter.h
        Json/JsonCharacter.cpp
        Json/JsonParser.h
        Json/JsonParser.cpp
        Json/JsonConfigs.h
        Json/JsonConfigs.cpp
        model/Game/Game.cpp model/Game/Game.h
        model/GameObjects_fight/GameObject/GameObject.cpp
        model/GameObjects_fight/GameObject/GameObject.h
        model/GameObjects_fight/Character/Character.cpp
        model/GameObjects_fight/Character/Character.h
        model/GameObjects_fight/Background/Background.cpp
        model/GameObjects_fight/Background/Background.h
        model/GameObject_charSelect/GameObject_charSelect.cpp
        model/GameObject_charSelect/GameObject_charSelect.h
        controllers/Controller/Renderable.cpp
        controllers/Controller/Renderable.h
        controllers/Controller/Controller.cpp
        controllers/Controller/Controller.h
        controllers/ViewController/ViewController.cpp
        controllers/ViewController/ViewController.h
        controllers/ViewController/ViewController_fight/ViewController_fight.cpp
        controllers/ViewController/ViewController_fight/ViewController_fight.h
        controllers/ViewController/ViewController_charSelect/ViewController_charSelect.cpp
        controllers/ViewController/ViewController_charSelect/ViewController_charSelect.h
        model/Game/ViewFactory/ViewFactory.cpp
        model/Game/ViewFactory/ViewFactory.h
        model/Game/GameObjectControllerFactory/GameObjectControllerFactory.cpp
        model/Game/GameObjectControllerFactory/GameObjectControllerFactory.h
        model/Game/GameObjectFactory/GameObjectFactory.cpp
        model/Game/GameObjectFactory/GameObjectFactory.h
        model/Viewmanager/ViewManager.cpp
        model/Viewmanager/ViewManager.h
        model/Game/ViewFactory/ViewFactory.cpp
        model/Game/ViewFactory/ViewFactory.h
        utils/Mapper/Mapper_fight/Mapper_fight.cpp
        utils/Mapper/Mapper_fight/Mapper_fight.h
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
        utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.cpp
        utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h
        Animations/CaptainAmericaAnimations/CaptainAmericaStillAnimation.cpp
        Animations/CaptainAmericaAnimations/CaptainAmericaStillAnimation.h
        Animations/CaptainAmericaAnimations/CaptainAmericaWalkFowardAnimation.cpp
        Animations/CaptainAmericaAnimations/CaptainAmericaWalkFowardAnimation.h
        Animations/CaptainAmericaAnimations/CaptainAmericaCrowchedDownAnimation.cpp
        Animations/CaptainAmericaAnimations/CaptainAmericaCrowchedDownAnimation.h
        Animations/CaptainAmericaAnimations/CaptainAmericaJumpAnimation.cpp
        Animations/CaptainAmericaAnimations/CaptainAmericaJumpAnimation.h
        Animations/CaptainAmericaAnimations/CaptainAmericaWalkBackwardsAnimation.cpp
        Animations/CaptainAmericaAnimations/CaptainAmericaWalkBackwardsAnimation.h
        Animations/SpiderManAnimations/SpiderManCrowchedDownAnimation.cpp
        Animations/SpiderManAnimations/SpiderManCrowchedDownAnimation.h
        Animations/SpiderManAnimations/SpiderManJumpAnimation.cpp
        Animations/SpiderManAnimations/SpiderManJumpAnimation.h
        Animations/SpiderManAnimations/SpiderManStillAnimation.cpp
        Animations/SpiderManAnimations/SpiderManStillAnimation.h
        Animations/SpiderManAnimations/SpiderManWalkAnimation.cpp
        Animations/SpiderManAnimations/SpiderManWalkAnimation.h
        utils/Mapper/Mapper_fight/Mapper_fight_1.cpp
        utils/Mapper/Mapper_fight/Mapper_fight_1.h
        utils/Mapper/Mapper_fight/Mapper_fight_2.cpp
        utils/Mapper/Mapper_fight/Mapper_fight_2.h
        utils/TeamManager/TeamManager.cpp
        utils/TeamManager/TeamManager.h
        Animations/VenomAnimations/VenomCrowchedDownAnimation.cpp
        Animations/VenomAnimations/VenomCrowchedDownAnimation.h
        Animations/VenomAnimations/VenomJumpAnimation.cpp
        Animations/VenomAnimations/VenomJumpAnimation.h
        Animations/VenomAnimations/VenomStillAnimation.cpp
        Animations/VenomAnimations/VenomStillAnimation.h
        Animations/VenomAnimations/VenomWalkBackwardsAnimation.cpp
        Animations/VenomAnimations/VenomWalkBackwardsAnimation.h
        Animations/VenomAnimations/VenomWalkFowardAnimation.h
        Animations/VenomAnimations/VenomWalkFowardAnimation.cpp
        utils/SpriteManagers/SpiderManSpriteManager/SpiderManSpriteManager.cpp
        utils/SpriteManagers/SpiderManSpriteManager/SpiderManSpriteManager.h
        utils/Logger/Logger.cpp utils/Logger/Logger.h
        utils/SpriteManagers/VenomSpriteManager/VenomSpriteManager.cpp
        utils/SpriteManagers/VenomSpriteManager/VenomSpriteManager.h
        utils/FlipManager/FlipManager.cpp
        utils/FlipManager/FlipManager.h
        utils/FlipManager/FlipManager.cpp utils/FlipManager/FlipManager.h
        Animations/ChunLiAnimations/ChunLiCrowchedDownAnimation.cpp
        Animations/ChunLiAnimations/ChunLiCrowchedDownAnimation.h
        Animations/ChunLiAnimations/ChunLiJumpAnimation.cpp
        Animations/ChunLiAnimations/ChunLiStillAnimation.cpp
        Animations/ChunLiAnimations/ChunLiJumpAnimation.h
        Animations/ChunLiAnimations/ChunLiStillAnimation.h
        Animations/ChunLiAnimations/ChunLiWalkBackwadsAnimation.cpp
        Animations/ChunLiAnimations/ChunLiWalkBackwadsAnimation.h
        Animations/ChunLiAnimations/ChunLiWalkFowardAnimation.cpp
        Animations/ChunLiAnimations/ChunLiWalkFowardAnimation.h
        utils/SpriteManagers/ChunLiSpriteManager/ChunLiSpriteManager.cpp
        utils/SpriteManagers/ChunLiSpriteManager/ChunLiSpriteManager.h
        Animations/VenomAnimations/VenomEnteringAnimation.h
        Animations/VenomAnimations/VenomEnteringAnimation.cpp
        Animations/SpiderManAnimations/SpiderManEnteringAnimation.h
        Animations/SpiderManAnimations/SpiderManEnteringAnimation.cpp
        Animations/ChunLiAnimations/ChunLiEnteringAnimation.h
        Animations/ChunLiAnimations/ChunLiEnteringAnimation.cpp
        Animations/CaptainAmericaAnimations/CaptainAmericaEnteringAnimation.h
        Animations/CaptainAmericaAnimations/CaptainAmericaEnteringAnimation.cpp
        utils/SpriteManagers/NotFoundSpriteManager.h
        utils/SpriteManagers/NotFoundSpriteManager.cpp
        Animations/NotFoundAnimation.h
        Animations/NotFoundAnimation.cpp
        utils/Mapper/Mapper_charSelect/Mapper_charSelect.cpp
        utils/Mapper/Mapper_charSelect/Mapper_charSelect.h
        utils/Mapper/Mapper_charSelect/Mapper_charSelect_1.cpp
        utils/Mapper/Mapper_charSelect/Mapper_charSelect_1.h
        utils/Mapper/Mapper_charSelect/Mapper_charSelect_2.cpp
        utils/Mapper/Mapper_charSelect/Mapper_charSelect_2.h
        utils/TextureManager/TextureManager.cpp
        utils/TextureManager/TextureManager.h
        views/View/View.cpp
        views/View/View.h
        Server/Server.cpp Server/Server.h
        Client/Client.cpp
        Client/Client.h
        utils/Mapper/Mapper.cpp utils/Mapper/Mapper.h
        views/View/View_charSelect.cpp
        views/View/View_charSelect.h
        views/View/View_fight.cpp
        views/View/View_fight.h
        Server/GameObject_server/GameObject_server.h
        Server/GameObject_server/GameObject_server.cpp
        Server/Character_server/Character_server.h
        Server/Character_server/Character_server.cpp
        Server/Background_server/Background_server.h
        Server/Background_server/Background_server.cpp
        model/Game/ViewControllerFactory/ViewControllerFactory.cpp
        model/Game/ViewControllerFactory/ViewControllerFactory.h
        Server/Game_server/Game_server.h
        Server/Game_server/Game_server.cpp
        model/Game/GameObjectServerFactory/GameObjectServerFactory.cpp
        model/Game/GameObjectServerFactory/GameObjectServerFactory.h
        utils/HitboxManager/HitboxManager.h
        utils/HitboxManager/HitboxManager.cpp
        utils/HitboxManager/ChunLiHitboxManager/ChunLiHitboxManager.cpp
        utils/HitboxManager/VenomHitBoxManager/VenomHitboxManager.cpp
        utils/HitboxManager/ChunLiHitboxManager/ChunLiHitboxManager.h
        utils/HitboxManager/SpiderManHitboxManager/SpiderManHitboxManager.h
        utils/HitboxManager/CaptainAmericaHitboxManager/CaptainAmericaHitboxManager.h
        utils/HitboxManager/VenomHitBoxManager/VenomHitboxManager.h
        utils/HitboxManager/SpiderManHitboxManager/SpiderManHitboxManager.cpp
        utils/HitboxManager/CaptainAmericaHitboxManager/CaptainAmericaHitboxManager.cpp
        utils/CollisionManager/CollisionManager.cpp
        utils/CollisionManager/CollisionManager.h


        Json/JsonGameObject_charSelect.cpp Json/JsonGameObject_charSelect.h Json/JsonSintax.cpp Json/JsonSintax.h Json/JsonDisconection.cpp Json/JsonDisconection.h Animations/CaptainAmericaAnimations/CaptainAmericaPunchAnimation.cpp Animations/CaptainAmericaAnimations/CaptainAmericaPunchAnimation.h Animations/ChunLiAnimations/ChunLiPunchAnimation.cpp Animations/ChunLiAnimations/ChunLiPunchAnimation.h Animations/SpiderManAnimations/SpiderManPunchAnimation.cpp Animations/SpiderManAnimations/SpiderManPunchAnimation.h Animations/VenomAnimations/VenomPunchAnimation.cpp Animations/VenomAnimations/VenomPunchAnimation.h)



target_link_libraries(app ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${CMAKE_DL_LIBS})

