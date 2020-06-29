# Testing library
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
)
FetchContent_MakeAvailable(catch2)
# Adds Catch2::Catch2

# Tests need to be added as executables first
add_executable(test_repo test_get.cpp)

# I'm using C++20 in the test
target_compile_features(test_repo PRIVATE cxx_std_20)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(test_repo PRIVATE githubpp::githubpp Catch2::Catch2 cpr::cpr)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME test_repotest COMMAND test_repo) # Command can be a target
