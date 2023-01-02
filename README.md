# C++ Math Library #

Small library to help with geometry and linear algebra for games.

## Requirements ##

To setup this project you will need:

* _CMake_ version 3.20 or heigher.
* Any version of _Visual Studio_ and _MSVC_ compiler.

Optionally you should install _clang-format_, _clang-tidy_ and _cppcheck_ and add them to the path.

## Setup ##

To clone the project:

	git clone <project_url>

To generate a build system go to the root of a project and use:

	cmake -S . -B <path_to_build_dir>

To build project using the cmake from command line:

	cmake --build <path_to_build_dir> --config <config_name>

To build specific target use:

	cmake --build <path_to_build_dir> --target <target_name>

The clang-format target will apply formatting to all files under apps, include and src folders. The cppcheck and clang-tidy targets will apply static-code analysis on all cpp and c files under src folders.

If you are using MSVC compiler you can use address sanitizer tool by setting the MATH_SANITIZER flag when invoking the cmake command:

	cmake -S <root_project_dir> -B <build_dir> -DMATH_SANITIZER=ON

If you want to use Unity builds use MATH_UNITY when invoking the cmake command:

	make -S <root_project_dir> -B <build_dir> -DMATH_UNITY=ON
