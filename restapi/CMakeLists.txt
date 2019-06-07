cmake_minimum_required (VERSION 2.6)
project (Dota2HeroPickerRest)

find_package (Pistache REQUIRED NO_MODULE)

add_executable (Dota2HeroPickerRest main.cpp)
target_link_libraries (Dota2HeroPickerRest pistache)

install (
    TARGETS Dota2HeroPickerRest
    RUNTIME DESTINATION bin
)