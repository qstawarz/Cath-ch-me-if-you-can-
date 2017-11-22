cmake_minimum_required(VERSION 3.8)
project(Catch_me_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp includes/Utils/Vector.h includes/Managers/IManager.h src/Managers/Game.cpp includes/Managers/Game.h src/Managers/DisplayManager.cpp includes/Managers/DisplayManager.h src/Managers/InputManager.cpp includes/Managers/InputManager.h includes/Actors/IActor.h src/Actors/Cat.cpp includes/Actors/Cat.h src/Utils/Sprite.cpp includes/Utils/Sprite.h src/Actors/Mouse.cpp includes/Actors/Mouse.h src/Utils/Text.cpp includes/Utils/Text.h src/Managers/UIManager.cpp includes/Managers/UIManager.h src/Actors/Box.cpp includes/Actors/Box.h includes/States/StateBase.h src/States/StatePlaying.cpp includes/States/StatePlaying.h src/States/StateGameOver.cpp includes/States/StateGameOver.h)
add_executable(Catch_me_ ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Catch_me_ ${SFML_LIBRARIES})
endif()