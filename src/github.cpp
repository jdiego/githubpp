#include "githubpp/github.hpp"
#include <cpr/cpr.h>
#include <iostream>
#include <fmt/core.h>

using namespace std::literals;

namespace githubpp
{
    Github::Github(std::string_view username, std::string_view password)
        : m_username{username}, m_password {password}
    {
        //
        const auto url = fmt::format("{0}/{1}", DEFAULT_BASE_URL, "/user/repos");
        cpr::Response r = cpr::Get(
            cpr::Url{DEFAULT_BASE_URL.data()}, 
            cpr::Authentication{username.data(), password.data()}
        );
        std::cout << r.text << std::endl;
    }

    Github::Github(std::string_view user_token): m_token{user_token}
    {
        //
        const auto url = fmt::format("{0}/{1}", DEFAULT_BASE_URL, "user");
        const auto token = fmt::format("token {}", user_token);
        cpr::Response r = cpr::Get(
            cpr::Url{url}, 
            cpr::Header{{"Authorization", token.c_str()}}
        );
    }
    void Github::rate_limit(){
        const auto url = fmt::format("{0}/{1}", DEFAULT_BASE_URL, "rate_limit");
        cpr::Response r = cpr::Get(cpr::Url{url});

        std::cout << "URL: " << url << "\n" << r.text << std::endl;

    }
} // namespace githubpp