#ifndef STEAMAPI_CLIENT_URL_ENCODER_HPP
#define STEAMAPI_CLIENT_URL_ENCODER_HPP
#include <curl-wrapper.hpp>
#include <map>
#include <string>

class UrlEncoder {
public:
    UrlEncoder();
    std::string urlEncodeMap(const std::map<std::string, std::string> &m);
private:
    CurlWrapper curl;
};
#endif // STEAMAPI_CLIENT_URL_ENCODER_HPP