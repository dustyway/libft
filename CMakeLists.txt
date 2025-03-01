cmake_minimum_required(VERSION 3.22.1)
project(libft VERSION 0.0.2 LANGUAGES C)

set(LIBRARY_NAME ft)
option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(include)

if(ENABLE_TESTING)
    add_subdirectory(tests)
endif()

include(Docs)
