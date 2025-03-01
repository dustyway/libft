project(libft-tests VERSION 0.0.2 LANGUAGES CXX)

set(TEST_SOURCES
        main.cpp
        libft_core/ft_atoi_test.cpp
        libft_addendum/absf_test.cpp
        mathematics/factorial_test.cpp)

add_executable(tests ${TEST_SOURCES})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(tests PRIVATE ft)
