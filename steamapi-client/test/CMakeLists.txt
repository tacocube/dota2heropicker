include(GoogleTest)

add_executable(steamapi-client-test "")
target_link_libraries(steamapi-client-test steamapi-client gtest gtest_main)
target_sources(steamapi-client-test PRIVATE
    steamapi-client-test.cpp
    test-main.cpp
)

gtest_discover_tests(steamapi-client-test)