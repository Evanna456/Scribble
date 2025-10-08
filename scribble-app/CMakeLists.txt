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

set(CMAKE_PREFIX_PATH "C://vcpkg/packages/fmt_x64-mingw-dynamic")
set(CMAKE_PREFIX_PATH "C://vcpkg/packages/fmt_x64-mingw-dynamic/share/fmt")
set(CMAKE_PREFIX_PATH "C://vcpkg/packages/glew_x64-mingw-dynamic/share/glew")
set(CMAKE_PREFIX_PATH "C://vcpkg/packages/glfw3_x64-mingw-dynamic/share/glfw3")

find_package(fmt CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(unofficial-nuklear CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-mingw-dynamic/include")

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PRIVATE nuklear)

