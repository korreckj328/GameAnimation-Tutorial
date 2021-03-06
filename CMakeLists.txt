cmake_minimum_required(VERSION 3.16)
project(GameAnimation_Tut)

set(CMAKE_CXX_STANDARD 14)

if (NOT APPLE) 
        find_package(OpenGL)
endif()

find_package(GLEW)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

add_subdirectory(glm)

add_subdirectory(freetype)

option(BUILD_BULLET2_DEMOS OFF)
option(BUILD_CPU_DEMOS OFF)
option(BUILD_EXTRAS OFF)
option(BUILD_OPENGL3_DEMOS OFF)
option(BUILD_UNIT_TESTS OFF)

add_subdirectory(bullet3)

include_directories("${CMAKE_SOURCE_DIR}/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/stb")
include_directories("${CMAKE_SOURCE_DIR}/glm")
include_directories("${CMAKE_SOURCE_DIR}/cgltf")
include_directories("${CMAKE_SOURCE_DIR}/bullet3/src")
include_directories("${CMAKE_SOURCE_DIR}/freetype/include")

file(GLOB PROJECT_SOURCES src/*.h
                          src/*.cpp
                          src/Animation/*.h
                          src/Animation/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} src/Animation/Frame.h)

if (NOT APPLE) 
        target_link_libraries(${PROJECT_NAME} OpenGL)
endif()

target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm)
target_link_libraries(${PROJECT_NAME} BulletDynamics BulletCollision LinearMath)
target_link_libraries(${PROJECT_NAME} freetype)
link_directories("${CMAKE_SOURCE_DIR}/stb")
link_directories("${CMAKE_SOURCE_DIR}/cgltf")


set (source "${CMAKE_SOURCE_DIR}/Assets")

set (destination "${CMAKE_CURRENT_BINARY_DIR}/Assets")

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "copy resources folder from ${source} => ${destination}"
)
