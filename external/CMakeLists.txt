#
add_subdirectory(boost)
add_subdirectory(fmt)
add_subdirectory(cpr)
#
if(ORACLE_USE_EXTERNAL_JSON)
  find_package(nlohmann_json 3.7.0 REQUIRED)
else()
  add_subdirectory(json)
endif()
# 