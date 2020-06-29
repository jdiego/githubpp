#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "githubpp/github.hpp"
#include <cpr/cpr.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <fmt/core.h>
TEST_CASE( "Auth via TOKEN", "[main]" ) {
    if(const char* token = std::getenv("GH_TOKEN"))
    {
        auto g = githubpp::Github(token);
        REQUIRE(g.token() == token);

        g.rate_limit();
    }   
    else {
        REQUIRE(false);
    }
}
