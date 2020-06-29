
find_package(fmt)

if (fmt_FOUND)
    message(STATUS "Using external FMT version at: ${fmt_VERSION}.")
    # Make found targets globally available.
    set_target_properties( 
        fmt::fmt    # This is header only
        PROPERTIES IMPORTED_GLOBAL TRUE 
    )
else()
    message(STATUS "Downloading FMT LIBRARY")
    # FMT library
    FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
    )
    FetchContent_MakeAvailable(fmt)
    # Adds fmt::fmt
    message(STATUS "Exporting FMT Library as fmt::fmt")
endif()

