cmake_minimum_required(VERSION 3.20)

project(
	MATH
	VERSION 0.1
	DESCRIPTION "C++ math library"
	LANGUAGES CXX)

# Include utils script
include(cmake/utils.cmake)

# Library build options
option(MATH_SANITIZER "Enable address sanitizer for MSVC builds" OFF)
option(MATH_UNITY "Enable unity builds" OFF)

message(STATUS "MATH_SANITIZER ${MATH_SANITIZER}")
message(STATUS "MATH_UNITY ${MATH_UNITY}")

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

	# Let's ensure -std=c++xx instead of -std=g++xx
  	set(CMAKE_CXX_EXTENSIONS OFF)

	# Configuration types
	SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

 	# Let's nicely support folders in IDEs
  	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  	# Setup address sanitizer if this option is selected
  	if (MATH_SANITIZER)
		if (MSVC)
			add_compile_options(/fsanitize=address)
		endif()
	endif()

  	# Include cmake scripts here
  	include(cmake/clang-format.cmake)
	include(cmake/cppcheck.cmake)

	# Turn on warnings as errors
	# Ignore warning for nameless structs
	add_compile_options(/W4 /WX /wd4201)

	# Multiprocessor compilation
	add_compile_options(/MP)
endif()

  	# The compiled library code is here
	add_subdirectory(src)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	include(FetchContent)

	SET(BUILD_GMOCK OFF)
	SET(INSTALL_GTEST OFF)
	FetchContent_Declare(
		gtest
		GIT_REPOSITORY https://github.com/google/googletest
		GIT_TAG        58d77fa8070e8cec2dc1ed015d66b454c8d78850 # release-1.12.1
	)
	FetchContent_MakeAvailable(gtest)

	# The executable code is here
	add_subdirectory(tests)
endif()
