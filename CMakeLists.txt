cmake_minimum_required(VERSION 3.18)
project(main LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(main main.c)
target_link_libraries(main PRIVATE PkgConfig::GTK4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
