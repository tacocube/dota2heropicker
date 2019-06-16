#ifndef STEAMAPI_CLIENT_IDOTA2MATCH_GETMATCHHISTORY_HPP
#define STEAMAPI_CLIENT_IDOTA2MATCH_GETMATCHHISTORY_HPP
#include <steamapi-client/steamapi-templates.hpp>
#include <boost/optional.hpp>
#include <rapidjson/document.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include <iostream>

namespace IDOTA2Match::GetMatchHistory { struct v1{}; }
template<> struct Request<IDOTA2Match::GetMatchHistory::v1> {
    enum struct GAMEMODE : std::uint32_t {
        None = 0,
        All_Pick = 1,
        Captains_Mode = 2,
        Random_Draft = 3,
        Single_Draft = 4,
        All_Random = 5,
        Intro = 6,
        Diretide = 7,
        Reverse_Captains_Mode = 8,
        The_Greeviling = 9,
        Tutorial = 10,
        Mid_Only = 11,
        Least_Played = 12,
        New_Player_Pool = 13,
        Compendium_Matchmaking = 14,
        Captains_Draft = 16
    };

    enum struct SKILL : std::uint32_t {
        Any = 0,
        Normal = 1,
        High = 2,
        Very_High = 3
    };

    boost::optional<std::uint32_t> hero_id;
    boost::optional<GAMEMODE> game_mode;
    boost::optional<SKILL> skill;
    boost::optional<std::uint32_t> min_players;
    boost::optional<std::uint32_t> account_id;
    boost::optional<std::uint64_t> league_id;
    boost::optional<std::uint64_t> start_at_match_id;
    boost::optional<std::uint32_t> matches_requested;
    boost::optional<bool> tournament_games_only;

    Request(boost::optional<std::uint32_t> hero_id,
        boost::optional<GAMEMODE> game_mode,
        boost::optional<SKILL> skill,
        boost::optional<std::uint32_t> min_players,
        boost::optional<std::uint32_t> account_id,
        boost::optional<std::uint64_t> league_id,
        boost::optional<std::uint64_t> start_at_match_id,
        boost::optional<std::uint32_t> matches_requested,
        boost::optional<bool> tournament_games_only) :
        hero_id(hero_id),
        game_mode(game_mode),
        skill(skill),
        min_players(min_players),
        account_id(account_id),
        league_id(league_id),
        start_at_match_id(start_at_match_id),
        matches_requested(matches_requested),
        tournament_games_only(tournament_games_only) {}

    std::map<std::string, std::string> getParameters() {
        std::map<std::string, std::string> m;
        if (hero_id.has_value()) m["hero_id"] = std::to_string(hero_id.get());
        if (game_mode.has_value()) m["game_mode"] = std::to_string(static_cast<std::uint32_t>(game_mode.get()));
        if (skill.has_value()) m["skill"] = std::to_string(static_cast<std::uint32_t>(skill.get()));
        if (min_players.has_value()) m["min_players"] = std::to_string(min_players.get());
        if (account_id.has_value()) m["account_id"] = std::to_string(account_id.get());
        if (league_id.has_value()) m["league_id"] = std::to_string(league_id.get());
        if (start_at_match_id.has_value()) m["start_at_match_id"] = std::to_string(start_at_match_id.get());
        if (matches_requested.has_value()) m["matches_requested"] = std::to_string(matches_requested.get());
        if (tournament_games_only.has_value()) m["tournament_games_only"] = tournament_games_only.get() ? "1" : "0";
        return m;
    }
};
template<> struct Response<IDOTA2Match::GetMatchHistory::v1> {
    struct Match {
        enum struct LOBBYTYPE : std::int32_t {
            Invalid = -1,
            Public_matchmaking = 0,
            Practise = 1,
            Tournament = 2,
            Tutorial = 3,
            Co_op_with_bots = 4,
            Team_match = 5,
            Solo_Queue = 6,
            Ranked_Matchmaking = 7,
            One_v_One_Solo_Mid = 8
        };
        struct Player {
            std::uint32_t account_id;
            std::uint8_t player_slot;
            std::uint64_t hero_id;
        };
        std::uint64_t match_id;
        std::uint64_t match_seq_num;
        std::uint64_t start_time;
        LOBBYTYPE lobby_type;
        std::vector<Player> players;
    };
    std::uint32_t status;
    std::string statusDetail;
    std::uint32_t num_results;
    std::uint32_t total_results;
    std::uint32_t results_remaining;
    std::vector<Match> matches;

    Response(const rapidjson::Document &doc) {
        auto result = doc["result"].GetObject();
        status = result["status"].GetUint();
        if (status == 1) {
            num_results = result["num_results"].GetUint();
            total_results = result["total_results"].GetUint();
            results_remaining = result["results_remaining"].GetUint();
            for (auto &m : result["matches"].GetArray()) {
                Match match;
                match.match_id = m["match_id"].GetUint64();
                match.match_seq_num = m["match_seq_num"].GetUint64();
                match.start_time = m["start_time"].GetUint64();
                match.lobby_type = static_cast<Match::LOBBYTYPE>(m["lobby_type"].GetInt());
                for (auto &p : m["players"].GetArray()) {
                    Match::Player player;
                    player.account_id = p["account_id"].GetUint();
                    player.player_slot = p["player_slot"].GetUint();
                    player.hero_id = p["hero_id"].GetUint64();
                    match.players.push_back(player);
                }
                matches.push_back(match);
            }
        } else {
            statusDetail = doc["statusDetail"].GetString();
        }
    }
};
template<> std::string interface<IDOTA2Match::GetMatchHistory::v1>(std::uint32_t app_id) {
    std::stringstream ss;
    ss << "IDOTA2Match_" << app_id;
    return ss.str();
}
template<> std::string method<IDOTA2Match::GetMatchHistory::v1>() { return "GetMatchHistory"; }
template<> std::string version<IDOTA2Match::GetMatchHistory::v1>() { return "1"; }
#endif // STEAMAPI_CLIENT_IDOTA2MATCH_GETMATCHHISTORY_HPP