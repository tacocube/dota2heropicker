#ifndef STEAMAPI_CLIENT_CURL_WRAPPER_HPP
#define STEAMAPI_CLIENT_CURL_WRAPPER_HPP
#include <memory>
extern "C"{
    #include <curl/curl.h>
}

class CurlWrapper {
public:
    CurlWrapper();
    std::string escape(const std::string &s);
    CURLcode setUrl(const std::string &url);
    typedef std::unique_ptr<char, decltype(&curl_free)> curl_str;

private:
    std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl;
};
#endif // STEAMAPI_CLIENT_CURL_WRAPPER_HPP