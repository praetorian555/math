# Add gtest dependency
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "GTest library included")
    option(BUILD_GMOCK "" OFF)
    option(INSTALL_GTEST "" OFF)
    add_subdirectory(gtest)
endif()
