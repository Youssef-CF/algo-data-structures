cmake_minimum_required(VERSION 3.17)
project(algo_data_structures)

set(CMAKE_CXX_STANDARD 14)
add_library(
        linkedlist
        src/linkedlist.hpp
        src/linkedlist.cpp
    )

target_include_directories(linkedlist PUBLIC src)
add_executable(ll_editor
        src/main.cpp)
target_link_libraries(ll_editor PRIVATE linkedlist)



add_executable(unit_test
        test/test_linkedlist.cpp
)
target_link_libraries(unit_test
        linkedlist
)


