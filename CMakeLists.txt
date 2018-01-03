cmake_minimum_required(VERSION 3.8)
project(prog3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${prog3_SOURCE_DIR}/cmake")
set(SOURCE_FILES jumpyBoy/hud/HUD.cpp jumpyBoy/hud/HUD.h rootEngine/level/Level.cpp rootEngine/level/Level.h Main.cpp rootEngine/System/GameEngine.cpp rootEngine/System/GameEngine.h rootEngine/System/System.cpp rootEngine/System/System.h rootEngine/sprite/Sprite.cpp rootEngine/sprite/Sprite.h rootEngine/sprite/HUDSprite.cpp rootEngine/sprite/HUDSprite.h rootEngine/sprite/PhysicsSprite.cpp rootEngine/sprite/PhysicsSprite.h jumpyBoy/player/Player.cpp jumpyBoy/player/Player.h rootEngine/level/LevelManager.cpp rootEngine/level/LevelManager.h rootEngine/sprite/NonCollEnvironmentSprite.cpp rootEngine/sprite/NonCollEnvironmentSprite.h jumpyBoy/player/PlayerState.h rootEngine/System/World.cpp rootEngine/System/World.h rootEngine/util/Timer.cpp rootEngine/util/Timer.h jumpyBoy/player/StandingState.cpp jumpyBoy/player/StandingState.h jumpyBoy/player/RunningState.cpp jumpyBoy/player/RunningState.h jumpyBoy/player/JumpingState.cpp jumpyBoy/player/JumpingState.h jumpyBoy/player/RunningJumpState.cpp jumpyBoy/player/RunningJumpState.h jumpyBoy/player/DeadState.cpp jumpyBoy/player/DeadState.h jumpyBoy/player/FallingState.cpp jumpyBoy/player/FallingState.h jumpyBoy/player/DodgingState.cpp jumpyBoy/player/DodgingState.h jumpyBoy/player/PlayerState.cpp jumpyBoy/player/RunningFallState.cpp jumpyBoy/player/RunningFallState.h jumpyBoy/enemy/Enemy.h jumpyBoy/enemy/Enemy.cpp jumpyBoy/enemy/FlyingEnemy.cpp jumpyBoy/enemy/FlyingEnemy.h jumpyBoy/enemy/WalkingEnemy.cpp jumpyBoy/enemy/WalkingEnemy.h rootEngine/UserInput/UserInputCallback.h rootEngine/UserInput/UserInput.cpp rootEngine/UserInput/UserInput.h rootEngine/UserInput/UserInputMgr.cpp rootEngine/UserInput/UserInputMgr.h rootEngine/UserInput/MemberFuncCallback.h rootEngine/UserInput/freeFuncCallback.cpp rootEngine/UserInput/freeFuncCallback.h rootEngine/collision/CollEngine.cpp rootEngine/collision/CollEngine.h rootEngine/interfaces/Drawable.h jumpyBoy/player/Controller.cpp jumpyBoy/player/Controller.h rootEngine/interfaces/PlayerInterface.h rootEngine/sprite/EnvironmentSprite.cpp rootEngine/sprite/EnvironmentSprite.h rootEngine/collision/CollisionStrategy.h jumpyBoy/player/KeyBindings.cpp jumpyBoy/player/KeyBindings.h rootEngine/System/World.cpp jumpyBoy/CollisionStrategies/PlayerCollBehavior.cpp jumpyBoy/CollisionStrategies/PlayerCollBehavior.h jumpyBoy/CollisionStrategies/GroundBehavior.cpp jumpyBoy/CollisionStrategies/GroundBehavior.h jumpyBoy/CollisionStrategies/FlyingEnemyBehavior.cpp jumpyBoy/CollisionStrategies/FlyingEnemyBehavior.h jumpyBoy/CollisionStrategies/CollisionVariables.cpp jumpyBoy/CollisionStrategies/CollisionVariables.h rootEngine/collision/CollisionVariables.h jumpyBoy/enemy/EnemyFactory.cpp jumpyBoy/enemy/EnemyFactory.h jumpyBoy/LevelFactory/LevelFactory.cpp jumpyBoy/LevelFactory/LevelFactory.h jumpyBoy/player/PlayerFactory.cpp jumpyBoy/player/PlayerFactory.h)
add_executable(prog3 ${SOURCE_FILES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(prog3 ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})