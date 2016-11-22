cmake_minimum_required(VERSION 3.0)
project (GameEngine)

# add compiler flags
add_definitions (
    -c
    -Wall
    )

# Header files
file(GLOB_RECURSE HDRS ${GameEngine_SOURCE_DIR}/src/*.h)

# Source files
file(GLOB_RECURSE SRCS
    ${GameEngine_SOURCE_DIR}/src/*.cpp
    ${GameEngine_SOURCE_DIR}/src/*.c
    )

# Define the executable
add_executable(GameEngine ${HDRS} ${SRCS})

# We need a CMAKE_DIR with some code to find external dependencies
SET(GameEngine_CMAKE_DIR "${GameEngine_SOURCE_DIR}/cmake")

#######################################
# LOOK for the packages that we need! #
#######################################

# OpenGL
find_package(OpenGL REQUIRED)

# GLEW
#INCLUDE(${GameEngine_CMAKE_DIR}/FindGLEW.cmake)

# SDL2
INCLUDE(${GameEngine_CMAKE_DIR}/FindSDL2.cmake)

# ASSIMP
INCLUDE(${GameEngine_CMAKE_DIR}/FindASSIMP.cmake)

# Define the include DIRs
include_directories(
    ${GameEngine_SOURCE_DIR}/headers
    ${GameEngine_SOURCE_DIR}/sources
    ${OPENGL_INCLUDE_DIRS}
    #${GLEW_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIRS}
    )

# Define the link libraries
target_link_libraries( GameEngine
    ${OPENGL_LIBRARIES}
    #${GLEW_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${ASSIMP_LIBRARIES}
    )
