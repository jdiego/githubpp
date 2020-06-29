#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "githubpp/github.hpp"
#include <cpr/cpr.h>
#include <cstdlib>
#include <string>
#include <string_view>

TEST_CASE( "Auth", "[main]" ) {
    const auto username = std::getenv("");
    const auto password = std::getenv("");
    const auto token = std::getenv("");
    auto g = githubpp::Github(username, password);
    REQUIRE(g.username() == username);
    
}
