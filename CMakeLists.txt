cmake_minimum_required (VERSION 2.6)
project (Dota2HeroPicker)
include (ExternalProject)

set (Dota2HeroPicker_INSTALL_PREFIX "${Dota2HeroPicker_BINARY_DIR}/prefix")
set (Dota2HeroPicker_DEFAULT_ARGS
    "-DCMAKE_PREFIX_PATH:PATH=${Dota2HeroPicker_INSTALL_PREFIX};${CMAKE_PREFIX_PATH}"
    "-DCMAKE_INSTALL_PREFIX:PATH=${Dota2HeroPicker_INSTALL_PREFIX}"
)

ExternalProject_Add (
    pistache
    PREFIX ${Dota2HeroPicker_INSTALL_PREFIX}
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/pistache"
    CMAKE_CACHE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=Release
        -DPISTACHE_BUILD_EXAMPLES:BOOL=false
        -DPISTACHE_BUILD_TESTS:BOOL=false
        -DPISTACHE_BUILD_DOCS:BOOL=false
        -DPISTACHE_USE_SSL:BOOL=false
        ${Dota2HeroPicker_DEFAULT_ARGS}
)

ExternalProject_Add (
    Dota2HeroPickerRest
    PREFIX ${Dota2HeroPicker_INSTALL_PREFIX}
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/restapi"
    CMAKE_CACHE_ARGS
        "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
        ${Dota2HeroPicker_DEFAULT_ARGS}
    DEPENDS pistache
)