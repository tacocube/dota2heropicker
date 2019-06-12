target_include_directories(steamapi-client PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(steamapi-client
    PUBLIC
    curl_wrapper.hpp
    steamapi_client.hpp
    url_encoder.hpp
)