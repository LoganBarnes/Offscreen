cmake_minimum_required(VERSION 3.7.0 FATAL_ERROR)
project(AirWaves)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

######################
### EXTERNAL REPOS ###
######################
include(DownloadProject)

### GLFW ###
download_project(PROJ glfw
        PREFIX thirdparty
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG master
        )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES ON CACHE BOOL "" FORCE)
set(GLFW_USE_OSMESA OFF CACHE BOOL "" FORCE)

# compile glfw with current project
add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
