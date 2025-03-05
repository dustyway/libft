cmake_minimum_required(VERSION 3.22.1)
project(libft VERSION 0.0.2 LANGUAGES C)
set(CMAKE_C_STANDARD 90)

set(LIBRARY_NAME ft)
option(ENABLE_LIBFT_TESTING "Enable a Unit Testing Build" ON)
option(ENABLE_WARNINGS "Enable compiler warnings for target" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable compiler warnings as errors" OFF)

option(ENABLE_SANITIZE_ADDR "Enable address sanitizer" ON)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanitizer" ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

if(ENABLE_WARNINGS)
    include(Warnings)
endif ()

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif ()


add_subdirectory(src)
add_subdirectory(include)
if(ENABLE_LIBFT_TESTING)
    add_subdirectory(tests)
endif()

include(Docs)
