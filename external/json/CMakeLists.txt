find_package(nlohmann_json)




# Testing library
set(JSON_BuildTests OFF CACHE INTERNAL "")  # Forces the value
set(JSON_MultipleHeaders ON CACHE INTERNAL "")

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
)
FetchContent_MakeAvailable(nlohmann_json)
# Adds nlohmann_json::nlohmann_json

