# Collect all header files so that we can add them to the IDE later
file(GLOB_RECURSE PRIVATE_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/tests/*[.h|.c|.cpp]")

# Make an automatic library - will be static or dynamic based on user setting
add_executable(math_tests ${PRIVATE_SOURCE_LIST})

# add math library dependency
target_link_libraries(math_tests math gtest)

# All users of this library will need at least C++17
target_compile_features(math_tests PUBLIC cxx_std_17)
