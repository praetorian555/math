# C++ Math Library #

## Requirements ##

To setup this project you will need:

* _CMake_ version 3.20 or heigher.
* Any version of _Visual Studio_ and _MSVC_ compiler.

Optionally you should install _clang-format_ and _cppcheck_ and add them to the path.

## Setup ##

To clone the project and include all submodulues:

	git clone --recurse-submodules <project_url>

If you already cloned the project but forgot the --recurse-submodules you can use the following commands:

	git submodule init
	git submodule update

To generate a build system go to the root of a project and use:

	cmake -S . -B <path_to_build_dir>

To build project using the cmake from command line:

	cmake --build <path_to_build_dir> --config <config_name>

If you installed the _clang-format_ and _cppcheck*_ tools you will have access to clang-format and cppcheck targets. They can be run either by building them in IDE or with following directive in command-line:

	cmake --build <build_dir> --target clang-format
	cmake --build <build_dir> --target cppcheck

The clang-format target will apply formatting to all files under apps, include and src folders. The cppcheck target will apply static-code analysis on all cpp and c files nder apps and src folders.

If you are using MSVC compiler you can use address sanitizer tool by setting the MATH_SANITIZER flag when invoking the cmake command:

	cmake -S <root_project_dir> -B <build_dir> -DMATH_SANITIZER=ON

If you want to use Unity builds use MATH_UNITY when invoking the cmake command:

	make -S <root_project_dir> -B <build_dir> -DMATH_UNITY=ON
