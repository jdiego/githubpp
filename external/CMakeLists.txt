#
add_subdirectory(boost)
find_package(fmt)
if (NOT ${FMT_FOUND})
  add_subdirectory(fmt)
endif()
add_subdirectory(cpr)
#
if(ORACLE_USE_EXTERNAL_JSON)
  find_package(nlohmann_json 3.7.0 REQUIRED)
else()
  add_subdirectory(json)
endif()
# 