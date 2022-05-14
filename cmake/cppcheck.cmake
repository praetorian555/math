find_program(CPPCHECK "cppcheck")

if (CPPCHECK)

    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.c
        ${PROJECT_SOURCE_DIR}/apps/*.cpp
        ${PROJECT_SOURCE_DIR}/apps/*.c
        ${PROJECT_SOURCE_DIR}/tests/*.cpp
        ${PROJECT_SOURCE_DIR}/tests/*.c
    )

    add_custom_target(
        cppcheck
        COMMAND cppcheck
        ${ALL_CXX_SOURCE_FILES}
        --std=c++17
        --enable=all
        -I ../include
        -I ../src
        -I ../apps
        --check-config
        -q
        --suppress=missingIncludeSystem
        --suppress=missingInclude
        --suppress=unmatchedSuppression
    )

else()
    message(WARNING "cppcheck program not found, the cppcheck build target will not be available!")
endif()
