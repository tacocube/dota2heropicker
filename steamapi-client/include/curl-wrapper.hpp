#ifndef STEAMAPI_CLIENT_CURL_WRAPPER_HPP
#define STEAMAPI_CLIENT_CURL_WRAPPER_HPP
#include <functional>
#include <memory>
extern "C"{
    #include <curl/curl.h>
}

class CurlWrapper {
public:
    CurlWrapper();
    std::string escape(const std::string &s);
    CURLcode perform();
    CURLcode setUrl(const std::string &url);
    CURLcode setWriteFunction(std::function<size_t(char*,size_t,size_t)> &&f);
    CURLcode setReadFunction(std::function<size_t(char*, size_t, size_t)> &&f);
    typedef std::unique_ptr<char, decltype(&curl_free)> curl_str;

private:
    static size_t writeFunctionWrapper(char *, size_t, size_t, void *);
    static size_t readFunctionWrapper(char *, size_t, size_t, void *);
    std::function<size_t(char*,size_t,size_t)> writeFunction;
    std::function<size_t(char*,size_t,size_t)> readFunction;
    std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl;
};
#endif // STEAMAPI_CLIENT_CURL_WRAPPER_HPP