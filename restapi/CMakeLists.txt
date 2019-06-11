find_package(Pistache REQUIRED)

add_executable (dota2heropickerrest "")
target_link_libraries(dota2heropickerrest pistache)

add_subdirectory(src)
add_subdirectory(include)

install(
    TARGETS dota2heropickerrest
    RUNTIME DESTINATION bin
)