#ifndef STEAMAPI_CLIENT_ISTEAMWEBAPIUTIL_GETSERVERINFO_HPP
#define STEAMAPI_CLIENT_ISTEAMWEBAPIUTIL_GETSERVERINFO_HPP
#include <cstdint>
#include <map>
#include <string>
#include <rapidjson/document.h>
#include <steamapi-client/steamapi-templates.hpp>

namespace ISteamWebAPIUtil::GetServerInfo { struct v1{}; }
template<> struct Request<ISteamWebAPIUtil::GetServerInfo::v1> {
    std::map<std::string, std::string> getParameters() {
        return std::map<std::string, std::string>();
    }
};
template<> struct Response<ISteamWebAPIUtil::GetServerInfo::v1> {
    Response(const rapidjson::Document &doc) {
        if (doc.HasMember("servertime") && doc["servertime"].IsInt64()) {
            servertime = doc["servertime"].GetInt64();
        }
        if (doc.HasMember("servertimestring") && doc["servertimestring"].IsString()) {
            servertimestring = doc["servertimestring"].GetString();
        }
    }
    std::int64_t servertime;
    std::string servertimestring;
};
template<> std::string interface<ISteamWebAPIUtil::GetServerInfo::v1>() { return "ISteamWebAPIUtil"; }
template<> std::string method<ISteamWebAPIUtil::GetServerInfo::v1>() { return "GetServerInfo"; }
template<> std::string version<ISteamWebAPIUtil::GetServerInfo::v1>() { return "1"; }
#endif // STEAMAPI_CLIENT_ISTEAMWEBAPIUTIL_GETSERVERINFO_HPP