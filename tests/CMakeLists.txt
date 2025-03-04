project(libft-tests VERSION 0.0.2 LANGUAGES CXX)

set(TEST_SOURCES
        libft_core/ft_atoi_test.cpp
        mathematics/abs_f_test.cpp
        mathematics/abs_i_test.cpp
        libft_addendum/lst_nth_test.cpp
        mathematics/factorial_test.cpp
        stack/stack_tests.cpp
        queue/queue_tests.cpp
)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(libft-tests ${TEST_SOURCES})
target_include_directories(libft-tests PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(libft-tests PRIVATE ft Catch2::Catch2WithMain)
