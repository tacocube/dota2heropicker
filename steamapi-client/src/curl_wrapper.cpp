#include <curl_wrapper.hpp>
#include <mutex>
CurlWrapper::CurlWrapper() : curl(nullptr, &curl_easy_cleanup) {
    // Initialize curl globally only once.
    static std::once_flag flag;
    std::call_once(flag, curl_global_init, CURL_GLOBAL_ALL);

    curl.reset(curl_easy_init());
}

std::string CurlWrapper::escape(const std::string &s) {
    curl_str cs(curl_easy_escape(curl.get(), s.c_str(), 0), curl_free);
    return std::string(cs.get());
}

CURLcode CurlWrapper::setUrl(const std::string &url) {
    return curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
}