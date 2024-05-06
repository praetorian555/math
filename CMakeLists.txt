cmake_minimum_required(VERSION 3.28)
project(MATH VERSION 0.1.0 LANGUAGES CXX)

option(MATH_BUILD_TESTS "Build tests" ON)
message(STATUS "MATH_BUILD_TESTS: ${MATH_BUILD_TESTS}")
option(MATH_HARDENING "Enable hardening options" ON)
message(STATUS "MATH_HARDENING: ${MATH_HARDENING}")
option(MATH_SHARED_LIBS "Build shared libraries" OFF)
message(STATUS "MATH_SHARED_LIBS: ${MATH_SHARED_LIBS}")

## C++ language configuration boilerplate, hide symbols by default
if (NOT DEFINED CMAKE_CXX_VISIBILITY_PRESET AND NOT DEFINED CMAKE_VISIBILITY_INLINES_HIDDEN)
	set(CMAKE_CXX_VISIBILITY_PRESET hidden)
	set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
endif ()

## Let MATH_SHARED_LIBS override BUILD_SHARED_LIBS
if (MATH_SHARED_LIBS)
	set(BUILD_SHARED_LIBS "${MATH_SHARED_LIBS}")
endif ()

# Configure desired compilation options and warnings
include(cmake/compiler-warnings.cmake)
include(cmake/compiler-options.cmake)
add_library(math_warnings INTERFACE)
add_library(math_options INTERFACE)
setup_compiler_warnings(math_warnings)
setup_compiler_options(math_options)

if (MATH_HARDENING)
	include(cmake/sanitizers.cmake)
	setup_sanitizers(math_options)
endif ()

# Setup math library target
set(MATH_FILES
		src/rng.cpp
		include/math/base.h
		include/math/bounds2.h
		include/math/bounds3.h
		include/math/math.h
		include/math/matrix4x4.h
		include/math/normal3.h
		include/math/point2.h
		include/math/point3.h
		include/math/point4.h
		include/math/projections.h
		include/math/quaternion.h
		include/math/rng.h
		include/math/rotator.h
		include/math/transform.h
		include/math/vector2.h
		include/math/vector3.h
		include/math/vector4.h
		${CMAKE_CURRENT_BINARY_DIR}/include/math/export.h
)
add_library(math ${MATH_FILES})
target_include_directories(math PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_include_directories(math PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(math PRIVATE math_warnings)
target_link_libraries(math PRIVATE math_options)
target_compile_features(math PUBLIC cxx_std_20)
set_target_properties(math PROPERTIES VERSION ${MATH_VERSION} SOVERSION ${MATH_VERSION_MAJOR})

## Generate the export header for math and attach it to the target
include(GenerateExportHeader)
generate_export_header(math EXPORT_FILE_NAME include/math/export.h)
target_compile_definitions(math PUBLIC "$<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:MATH_STATIC_DEFINE>")
target_include_directories(math PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>")
target_include_directories(math PUBLIC "$<INSTALL_INTERFACE:include>")

# Install the library
install(TARGETS math
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # For Windows DLL files
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		PATTERN "*.hpp")
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		PATTERN "*.hpp")

if (MATH_BUILD_TESTS)
	include(FetchContent)
	SET(BUILD_GMOCK OFF)
	SET(INSTALL_GTEST ON)
	FetchContent_Declare(
			gtest
			GIT_REPOSITORY https://github.com/google/googletest
			GIT_TAG        58d77fa8070e8cec2dc1ed015d66b454c8d78850 # release-1.12.1
	)
	FetchContent_MakeAvailable(gtest)

	set(MATH_TEST_FILES
			test/base-test.cpp
			test/bounds2-test.cpp
			test/bounds3-test.cpp
			test/matrix4x4-test.cpp
			test/misc-test.cpp
			test/normal3-test.cpp
			test/point2-test.cpp
			test/point3-test.cpp
			test/point4-test.cpp
			test/projections-test.cpp
			test/quaternion-test.cpp
			test/transform-test.cpp
			test/vector2-test.cpp
			test/vector3-test.cpp
			test/vector4-test.cpp)
	add_executable(math_test ${MATH_TEST_FILES})
	target_link_libraries(math_test math)
	target_link_libraries(math_test math_warnings)
	target_link_libraries(math_test math_options)
	target_link_libraries(math_test gtest gtest_main)
	enable_testing()
	add_test(NAME math_test COMMAND math_test)
	# Install the test executable
	install(TARGETS math_test
			LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
			ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
			RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # For Windows DLL files
	)
endif ()
