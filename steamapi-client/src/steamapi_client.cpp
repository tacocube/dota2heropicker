#include <steamapi_client.hpp>
#include <mutex>
SteamApiClient::SteamApiClient() {
    // Initialize curl globally only once.
    static std::once_flag flag;
    std::call_once(flag, curl_global_init, CURL_GLOBAL_ALL);
}