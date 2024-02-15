cmake_minimum_required(VERSION 3.26)
project(EducationProject C)

set(CMAKE_C_STANDARD 99)

add_executable(EducationProject main.c
        lib/algorithms/array/array.c
        lib/algorithms/array/array.h
        lib/algorithms/algorithm.c
        lib/algorithms/algorithm.h
        lib/data_structures/bitset/bitset.c
        lib/data_structures/bitset/bitset.h
        lab_16.c
)
add_subdirectory(lib)
target_link_libraries(EducationProject algorithms)
target_link_libraries(EducationProject data_structures)


