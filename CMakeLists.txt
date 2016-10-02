cmake_minimum_required(VERSION 3.6)
project(RottenFish)

set(CMAKE_CXX_STANDARD 11)

set(rottenfish_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#add_definitions(-std=gnu++0x)

set(SOURCE_FILES_LIB
        ${rottenfish_SOURCE_DIR}/RottenFish/RottenFish.cpp
        ${rottenfish_SOURCE_DIR}/RottenFish/RottenFish.h
        ${rottenfish_SOURCE_DIR}/RottenFish/new_experiences.cpp
        ${rottenfish_SOURCE_DIR}/RottenFish/new_experiences.h
        ${rottenfish_SOURCE_DIR}/RottenFish/XorShiftMarsagliaBitsReserve.cpp
        ${rottenfish_SOURCE_DIR}/RottenFish/XorShiftMarsagliaBitsReserve.h
    )

set(SOURCE_FILES main.cpp ${SOURCE_FILES_LIB} RottenFish/Log2.cpp RottenFish/Log2.h)
add_executable(RottenFish ${SOURCE_FILES})


add_subdirectory(Tests)




