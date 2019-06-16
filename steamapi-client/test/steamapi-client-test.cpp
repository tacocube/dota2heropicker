#include <steamapi-client/steamapi-client.hpp>
#include <steamapi-client/IDOTA2Match/GetMatchHistory.hpp>
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

TEST(SteamClientApi, GetMatchHistory) {
    SteamApiClient c;
    Request<IDOTA2Match::GetMatchHistory::v1> req({},{},{},{},{},{},{},{}, false);
    auto res = c.get<IDOTA2Match::GetMatchHistory::v1>(570, req);
    ASSERT_EQ(static_cast<int>(res.status), 1);
    ASSERT_LE(res.num_results, res.total_results);
}