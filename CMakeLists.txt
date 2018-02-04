project (Stor)

cmake_minimum_required(VERSION 2.8)

add_subdirectory(utils)
add_subdirectory(local)
add_subdirectory(ut)

# file( GLOB SRCS "*.h *.cpp")
aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

target_link_libraries(${PROJECT_NAME} Utils)
