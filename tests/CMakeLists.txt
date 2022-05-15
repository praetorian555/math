# Collect all header files so that we can add them to the IDE later
file(GLOB_RECURSE PRIVATE_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/tests/*[.h|.c|.cpp]")
file(GLOB_RECURSE UNITY_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/build/tests/*.cxx")

# Make an automatic library - will be static or dynamic based on user setting
add_executable(math_tests ${PRIVATE_SOURCE_LIST})

# add math library dependency
target_link_libraries(math_tests math gtest)

# All users of this library will need at least C++17
target_compile_features(math_tests PUBLIC cxx_std_17)

# Compiler options
target_compile_options(math_tests PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Enable unity build
if (ENABLE_UNITY)
    set_target_properties(math_tests PROPERTIES UNITY_BUILD TRUE)
endif()

source_group(
  TREE "${PROJECT_SOURCE_DIR}/tests"
  PREFIX "Tests"
  FILES ${PRIVATE_SOURCE_LIST}
)

if (ENABLE_UNITY)
  source_group(
    TREE "${PROJECT_SOURCE_DIR}/build/tests/CMakeFiles/math_tests.dir/Unity"
    PREFIX "Unity"
    FILES ${UNITY_SOURCE_LIST}
  )
endif()
