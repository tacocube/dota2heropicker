#include <steamapi_client.hpp>
#include <curl_wrapper.hpp>
#include <url_encoder.hpp>
#include <sstream>

SteamApiClient::SteamApiClient() : steamApiHost("https://api.steampowered.com") {

}

rapidjson::Document SteamApiClient::callSteamApi(
    const std::string &interface,
    const std::string &method,
    const std::string &version,
    const std::map<std::string, std::string> &parameters) {

    CurlWrapper curl;
    UrlEncoder encoder;
    std::stringstream url;
    url << steamApiHost << "/";
    url << interface << "/";
    url << method << "/";
    url << "v" << version << "/";
    url << "?" << encoder.urlEncodeMap(parameters);
    curl.setUrl(url.str());
    
    return rapidjson::Document();
}
