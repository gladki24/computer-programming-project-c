# cmake_minimum_required(VERSION <specify CMake version here>)
project(src C)

set(CMAKE_C_STANDARD 90)

add_executable(src main.c modules/cli/cli.c modules/cli/cli.h modules/file/file.c modules/file/file.h modules/logic/logic.c modules/logic/logic.h modules/utils/utils.c modules/utils/utils.h modules/structures.h modules/configuration.h)