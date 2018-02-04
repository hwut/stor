aux_source_directory(. DIR_UT_SRCS)

add_executable(ut ${DIR_UT_SRCS})

target_link_libraries(ut CppUnitLite Utils Local)
