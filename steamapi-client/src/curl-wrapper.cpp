#include <curl-wrapper.hpp>
#include <iostream>
#include <mutex>
CurlWrapper::CurlWrapper() : curl(nullptr, &curl_easy_cleanup) {
    // Initialize curl globally only once.
    static std::once_flag flag;
    std::call_once(flag, curl_global_init, CURL_GLOBAL_ALL);

    curl.reset(curl_easy_init());

    // Redirect curl callback functions.
    curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, &CurlWrapper::writeFunctionWrapper);
    setWriteFunction([](char *ptr, size_t size, size_t nmemb) -> size_t {
        size_t len = size * nmemb;
        std::cout.write(ptr, len);
        return len;
    });
    curl_easy_setopt(curl.get(), CURLOPT_READFUNCTION, &CurlWrapper::readFunctionWrapper);
    setReadFunction([](char *ptr, size_t size, size_t nmemb) -> size_t {
        size_t len = size * nmemb;
        std::cin.read(ptr, len);
        return len;
    });
}

std::string CurlWrapper::escape(const std::string &s) {
    curl_str cs(curl_easy_escape(curl.get(), s.c_str(), 0), curl_free);
    return std::string(cs.get());
}

CURLcode CurlWrapper::perform() {
    return curl_easy_perform(curl.get());
}

CURLcode CurlWrapper::setUrl(const std::string &url) {
    return curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
}

CURLcode CurlWrapper::setWriteFunction(std::function<size_t(char*,size_t,size_t)> &&f) {
    writeFunction = f;
    return curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &writeFunction);
}

CURLcode CurlWrapper::setReadFunction(std::function<size_t(char*,size_t,size_t)> &&f) {
    readFunction = f;
    return curl_easy_setopt(curl.get(), CURLOPT_READDATA, &readFunction);
}

size_t CurlWrapper::writeFunctionWrapper(char *ptr, size_t size, size_t nmemb, void *userdata) {
    auto f = static_cast<std::function<size_t(char *, size_t, size_t)> *>(userdata);
    if (f == nullptr) return 0;
    return (*f)(ptr, size, nmemb);
}

size_t CurlWrapper::readFunctionWrapper(char *ptr, size_t size, size_t nmemb, void *userdata) {
    auto f = static_cast<std::function<size_t(char *, size_t, size_t)> *>(userdata);
    if (f == nullptr) return 0;
    return (*f)(ptr, size, nmemb);
}