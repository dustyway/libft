project(libft-tests VERSION 0.0.2 LANGUAGES CXX)

add_executable(tests main.cpp)
target_link_libraries(tests ft)
