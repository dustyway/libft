project(libft-tests VERSION 0.0.2 LANGUAGES CXX)

set(SRC main.cpp factorial_test.cpp)

add_executable(tests ${SRC})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(tests PRIVATE ft)
