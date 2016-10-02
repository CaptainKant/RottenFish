#project(RottenFishTests)

add_subdirectory(Lib2/googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

add_subdirectory(BasicTests)

