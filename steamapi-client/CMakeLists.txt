add_library(steamapi-client OBJECT "")
set_target_properties(steamapi-client PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(steamapi-client-shared SHARED $<TARGET_OBJECTS:steamapi-client>)
add_library(steamapi-client-static STATIC $<TARGET_OBJECTS:steamapi-client>)

add_subdirectory(include)
add_subdirectory(src)

install(
    TARGETS steamapi-client-shared
    EXPORT steamapi-client-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
    TARGETS steamapi-client-static
    EXPORT steamapi-client-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)