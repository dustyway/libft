cmake_minimum_required(VERSION 3.22.1)
project(libft VERSION 0.0.2 LANGUAGES C)

#option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

add_subdirectory(src)
add_subdirectory(include)

#set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
#include(Docs)
#
#if(ENABLE_TESTING)
#    add_subdirectory(tests)
#endif()