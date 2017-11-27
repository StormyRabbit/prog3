cmake_minimum_required(VERSION 3.8)
project(prog3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${prog3_SOURCE_DIR}/cmake")
set(SOURCE_FILES sprite.cpp sprite.h HUD.cpp HUD.h Level.cpp Level.h spriteWithPhysics.cpp spriteWithPhysics.h nonPhysicsSprite.cpp nonPhysicsSprite.h PCSprite.cpp PCSprite.h npcSprite.cpp npcSprite.h objSprite.cpp objSprite.h Observer.h Subject.h HUDElement.cpp HUDElement.h Main.cpp GameEngine.cpp GameEngine.h Subject.cpp)
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