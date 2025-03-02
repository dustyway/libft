cmake_minimum_required(VERSION 3.22.1)
project(libft VERSION 0.0.2 LANGUAGES C)
set(CMAKE_C_STANDARD 90)

set(LIBRARY_NAME ft)
option(ENABLE_LIBFT_TESTING "Enable a Unit Testing Build" ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(main)
if(ENABLE_LIBFT_TESTING)
    add_subdirectory(tests)
endif()

include(Docs)
