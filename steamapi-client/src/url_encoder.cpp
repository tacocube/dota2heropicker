#include <url_encoder.hpp>
#include <sstream>
UrlEncoder::UrlEncoder() : curl() {}
std::string UrlEncoder::urlEncodeMap(const std::map<std::string, std::string> &m) {
    std::stringstream ss;

    bool first = true;
    for (auto e : m) {
        if (first) {
            first = false;
        } else {
            ss << "&";
        }
        ss << curl.escape(e.first);
        ss << "=";
        ss << curl.escape(e.second);
    }

    return ss.str();
}