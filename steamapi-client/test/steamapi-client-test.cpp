#include <steamapi-client/steamapi-client.hpp>
#include <steamapi-client/ISteamWebAPIUtil/GetServerInfo.hpp>
#include <gtest/gtest.h>

TEST(SteamClientApi, Construction) {
    SteamApiClient c1;
    SteamApiClient c2;
    SteamApiClient c3;
}

TEST(SteamClientApi, GetServerInfo) {
    SteamApiClient c;
    Request<ISteamWebAPIUtil::GetServerInfo::v1> req;
    auto res = c.get<ISteamWebAPIUtil::GetServerInfo::v1>(req);
    ASSERT_GT(res.servertime, 100);
    ASSERT_GT(res.servertimestring.length(), 5);
}