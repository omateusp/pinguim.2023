cmake_minimum_required(VERSION 3.0.0)
project(penguins-game VERSION 0.1.0)

include(CTest)
enable_testing()

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
link_libraries(SDL2 SDL2_image SDL2_ttf SDL2_mixer)
include_directories(/usr/include/SDL2)

add_executable(penguins-game src/main.cpp src/Game.cpp src/Music.cpp src/Sprite.cpp src/State.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
