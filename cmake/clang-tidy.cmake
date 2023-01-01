find_program(CLANGTIDY "clang-tidy")

if (CLANGTIDY)

    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.c
    )

    add_custom_target(
        clang-tidy
        COMMAND clang-tidy
        -config-file=../.clang-tidy
        ${ALL_CXX_SOURCE_FILES}
        --
        -I../build/_deps/gtest-src/googletest/include
        -I../include
        -I../src
        -I../tests
    )

else()
    message(WARNING "clang-tidy program not found, the clang-tidy build target will not be available!")
endif()
