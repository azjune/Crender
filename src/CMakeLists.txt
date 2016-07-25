cmake_minimum_required(VERSION 3.3)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "app" )

## Set our project name
project(${PROJECT_NAME})

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "*.cpp" "*.c")

find_package(OpenGL REQUIRED)
set(INCLUDES ${OPENGL_INCLUDE_DIRS})
set(LIBS ${OPENGL_LIBRARIES})

## glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${EXTERNAL_DIR}/glfw/)

set(INCLUDES ${INCLUDES} ${EXTERNAL_DIR}/glfw/include/)
set(LIBS ${LIBS} glfw)

add_subdirectory(${EXTERNAL_DIR}/assimp/)
set(INCLUDES ${INCLUDES} ${EXTERNAL_DIR}/assimp/include/)
set(LIBS ${LIBS} assimp)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(X11 REQUIRED)
    set(INCLUDES ${INCLUDES} ${X11_INCLUDE_DIRS})
    set(LIBS ${LIBS} ${X11_LIBRARIES})
endif()

include_directories(${INCLUDES})
## Define the executable
add_executable(${PROJECT_NAME} ${SRCS} Docment.cpp Docment.h)
# target_include_directories(${PROJECT_NAME} ${INCLUDES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
