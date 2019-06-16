#ifndef STEAMAPI_CLIENT_STEAMAPI_CLIENT_HPP
#define STEAMAPI_CLIENT_STEAMAPI_CLIENT_HPP
extern "C"{
    #include <curl/curl.h>
}
#include <rapidjson/document.h>
#include <steamapi-client/steamapi-templates.hpp>
#include <string>
#include <map>
#include <memory>

class SteamApiClient{
public:
    SteamApiClient();
    template<class API>
    Response<API> get(Request<API> req) {
        std::map<std::string, std::string> parameters = req.getParameters();
        rapidjson::Document doc = callSteamApi(interface<API>(), method<API>(), version<API>(), parameters);
        return Response<API>(doc);
    }
    template<class API>
    Response<API> get(std::uint32_t app_id, Request<API> req) {
        std::map<std::string, std::string> parameters = req.getParameters();
        rapidjson::Document doc = callSteamApi(interface<API>(app_id), method<API>(), version<API>(), parameters);
        return Response<API>(doc);
    }
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