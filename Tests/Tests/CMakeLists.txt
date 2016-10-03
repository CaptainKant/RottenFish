
add_executable(runBasicLoadingtest loading_check.cpp ${SOURCE_FILES} )

add_executable(runRandomChecktest random_check.cpp ${SOURCE_FILES} )

add_executable(runLog2test log2_check.cpp ${SOURCE_FILES} )

add_executable(runRottenFishtest rottenfish_check.cpp ${SOURCE_FILES} )

add_executable(runAllTests all_tests.cpp ${SOURCE_FILES} )

target_link_libraries(runBasicLoadingtest gtest gtest_main )
target_link_libraries(runRandomChecktest gtest gtest_main )
target_link_libraries(runLog2test gtest gtest_main )
target_link_libraries(runRottenFishtest gtest gtest_main )
target_link_libraries(runAllTests gtest gtest_main )


