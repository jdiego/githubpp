#ifndef GITHUBPP_INCLUDED
#define GITHUBPP_INCLUDED

#include <string_view>
#include <string>

namespace githubpp {

    constexpr std::string_view  DEFAULT_BASE_URL = "https://api.github.com";
    constexpr std::string_view  DEFAULT_STATUS_URL = "https://status.github.com";
    // As of 2018-05-17, Github imposes a 10s limit for completion of API requests.
    // Thus, the timeout should be slightly > 10s to account for network/front-end
    // latency.
    const int DEFAULT_TIMEOUT = 15;
    const int DEFAULT_PER_PAGE = 30;


    class Github {

        public:

            Github(std::string_view username, std::string_view password);
            Github(std::string_view token);

            std::string username() const { return this->m_username;}
            std::string password() const { return this->m_password;}
            std::string token() const { return this->m_token; }
        private:
            std::string m_username;
            std::string m_password;
            std::string m_token;

    };

}
#endif