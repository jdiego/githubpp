##############################################
# Create target and set properties
##############################################
##############################################
# Create target and set properties
add_library(githubpp OBJECT)

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.
# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/githubpp/*.hpp")

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})

target_sources(githubpp
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/github.cpp
)
##############################################
# Create target and set properties

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(githubpp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_features(githubpp PUBLIC cxx_std_20)
target_compile_options(githubpp
    PRIVATE
       $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
           -pipe -march=native
           $<$<CONFIG:Debug>:-O0 -ggdb -Wall -Wextra -Weffc++ 
           -Wno-error=effc++ -fsanitize=address,undefined -fno-omit-frame-pointer -lasan -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization 
           -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs 
           -Wnoexcept -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion 
           -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef 
           -Werror -Wno-unused>>
       $<$<CXX_COMPILER_ID:MSVC>:
           $<$<CONFIG:Debug>:/Od /Wall /Zi>>
)

target_link_libraries(githubpp
    INTERFACE
        Boost::boost
        nlohmann_json::nlohmann_json
    PRIVATE
        Boost::boost
        nlohmann_json::nlohmann_json
        cpr::cpr
        fmt::fmt
        
)

# Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(githubpp::githubpp ALIAS githubpp)
set_target_properties(githubpp PROPERTIES EXPORT_NAME githubpp)
# So that another folders could refer to DBO without finding the package.
export(PACKAGE githubpp)

