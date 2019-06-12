cmake_minimum_required(VERSION 3.13)
project(Dota2HeroPicker)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)

add_subdirectory(restapi)
add_subdirectory(steamapi-client)