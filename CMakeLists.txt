cmake_minimum_required(VERSION 3.6)
project(Rottenfish)

set(CMAKE_CXX_STANDARD 11)

set(rottenfish_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)


set(SOURCE_FILES
        ${rottenfish_SOURCE_DIR}/RottenFish.cpp
        ${rottenfish_SOURCE_DIR}/RottenFish.h
        ${rottenfish_SOURCE_DIR}/RawSamplingReference.cpp
        ${rottenfish_SOURCE_DIR}/RawSamplingReference.h
        ${rottenfish_SOURCE_DIR}/XorShiftMarsagliaBitsReserve.cpp
        ${rottenfish_SOURCE_DIR}/XorShiftMarsagliaBitsReserve.h
    )

add_executable(Example example.cpp ${SOURCE_FILES})


add_subdirectory(Tests)




