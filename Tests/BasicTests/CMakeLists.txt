
add_executable(runBasicLoadingtest loading_check.cpp ${SOURCE_FILES_LIB} )

add_executable(runRandomChecktest random_check.cpp ${SOURCE_FILES_LIB} rottenfish_test.cpp)

add_executable(runLog2test log2_check.cpp ${SOURCE_FILES_LIB} )

add_executable(runRottenFishtest rottenfish_test.cpp ${SOURCE_FILES_LIB} )

target_link_libraries(runBasicLoadingtest gtest gtest_main )
target_link_libraries(runRandomChecktest gtest gtest_main )
target_link_libraries(runLog2test gtest gtest_main )
target_link_libraries(runRottenFishtest gtest gtest_main )


