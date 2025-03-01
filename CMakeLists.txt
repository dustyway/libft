cmake_minimum_required(VERSION 3.22.1)
project(libft VERSION 0.0.2 LANGUAGES C)

set(LIBRARY_NAME ft)
option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

add_subdirectory(src)
add_subdirectory(include)

if(ENABLE_TESTING)
    include(FetchContent)

    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2
            GIT_TAG v2.13.10
            GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

    add_subdirectory(tests)
endif()

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(Docs)

#if(ENABLE_TESTING)
#    add_subdirectory(tests_backup)
#endif()