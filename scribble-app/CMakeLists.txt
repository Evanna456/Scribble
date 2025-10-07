cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_COMPILER "C://MinGW/bin/g++.exe")

set(CMAKE_C_COMPILER "C://MinGW/bin/gcc.exe")

set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")

set(VCPKG_HOST_TRIPLET "x64-mingw-dynamic")

project(Scribble)

list(APPEND CMAKE_PREFIX_PATH "C://vcpkg/packages/sdl2_x64-mingw-dynamic")
list(APPEND CMAKE_PREFIX_PATH "C://vcpkg/packages/glew_x64-mingw-dynamic")

find_package(fmt CONFIG REQUIRED)
find_package(unofficial-nuklear CONFIG REQUIRED)

# set(SDL2_DIR "C://vcpkg/packages/sdl2_x64-mingw-dynamic/share/sdl2")
find_package(SDL2 CONFIG REQUIRED)

# set(GLEW_INCLUDE_DIR "C://vcpkg/packages/glew_x64-mingw-dynamic/include/GL")
# set(GLEW_LIBRARY "C://vcpkg/packages/glew_x64-mingw-dynamic/lib")
find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-mingw-dynamic/include")

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
target_link_libraries(${PROJECT_NAME} PRIVATE nuklear)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    SDL2::SDL2
    SDL2::SDL2main
)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)