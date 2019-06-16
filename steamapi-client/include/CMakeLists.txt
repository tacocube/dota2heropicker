target_include_directories(steamapi-client PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(steamapi-client
    PUBLIC
        steamapi-client/IDOTA2Match/GetMatchHistory.hpp
        steamapi-client/ISteamWebAPIUtil/GetServerInfo.hpp
        steamapi-client/steamapi-client.hpp
        steamapi-client/steamapi-templates.hpp
    PRIVATE
        curl-wrapper.hpp
        url-encoder.hpp
)