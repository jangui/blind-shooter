cmake_minimum_required(VERSION 3.24)
project(blind_shooter)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

add_executable(blind_shooter main.cpp Game.cpp Game.h Map.cpp Map.h DataTypes.h Renderer.cpp Renderer.h GameWindow.cpp GameWindow.h Obstacle.cpp Obstacle.h MapEntity.cpp MapEntity.h Entity.cpp Entity.h Player.cpp Player.h)

# Link SDL2
target_link_libraries(blind_shooter SDL2::SDL2 SDL2::SDL2main)
