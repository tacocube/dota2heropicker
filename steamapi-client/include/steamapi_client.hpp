#ifndef STEAMAPI_CLIENT_STEAMAPI_CLIENT_HPP
#define STEAMAPI_CLIENT_STEAMAPI_CLIENT_HPP
extern "C"{
    #include <curl/curl.h>
}
#include <rapidjson/document.h>
#include <string>
#include <map>
#include <memory>

class SteamApiClient{
public:
    SteamApiClient();
private:
    rapidjson::Document callSteamApi(
        const std::string &interface,
        const std::string &method,
        const std::string &version,
        const std::map<std::string, std::string> &parameters);
    std::string urlEncodeMap(const std::map<std::string, std::string> &parameters);
    
    const std::string steamApiHost;
};
#endif // STEAMAPI-CLIENT_STEAMAPI_CLIENT_HPP