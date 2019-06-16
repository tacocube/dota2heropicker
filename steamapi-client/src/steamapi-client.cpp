#include <steamapi-client/steamapi-client.hpp>
#include <curl-wrapper.hpp>
#include <url-encoder.hpp>
#include <sstream>
#include <cstdlib>

SteamApiClient::SteamApiClient() : steamApiHost("https://api.steampowered.com") {

}

rapidjson::Document SteamApiClient::callSteamApi(
    const std::string &interface,
    const std::string &method,
    const std::string &version,
    const std::map<std::string, std::string> &parameters) {

    CurlWrapper curl;
    UrlEncoder encoder;

    auto parametersPlusKey = parameters;
    parametersPlusKey["key"] = std::string(std::getenv("STEAMAPIKEY"));

    std::stringstream url;
    url << steamApiHost << "/";
    url << interface << "/";
    url << method << "/";
    url << "v" << version << "/";
    url << "?" << encoder.urlEncodeMap(parametersPlusKey);
    curl.setUrl(url.str());

    std::stringstream in;
    curl.setWriteFunction([&in](char *ptr, size_t size, size_t nmemb) -> size_t {
        size_t ret = size*nmemb;
        std::string s(ptr, ret);
        in << s;
        return ret;
    });
    curl.perform();
    rapidjson::Document d;
    d.Parse(in.str().c_str());
    return d;
}
