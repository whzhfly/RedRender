cmake_minimum_required(VERSION 3.0.0)
project(temple_test VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 20)


include_directories(CMAKE_SOURCE_DIR)
include_directories(CMAKE_SOURCE_DIR/math)

# https://stackoverflow.com/questions/22176957/cmake-finds-more-than-one-main-function
# file(GLOB_RECURSE HEADERS "./*.hpp")
# file(GLOB_RECURSE SOURCES "./*.cpp")

# file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/*.hpp")
# file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")

set(CMAKE_BUILD_TYPE "Debug")
# SET(TARGET_SRC ${HEADERS} ${SOURCES})



aux_source_directory(./render_system SYSTEM_DIR)
aux_source_directory(./game GAMES_DIR)
aux_source_directory(./math MATH_DIR)
aux_source_directory(./resource RESOURCE_DIR)

message(STATUS "HEADERS ${HEADERS}")
message(STATUS "SOURCES ${SOURCES}")

# aux_source_directory(src sourceList)
# aux_source_directory(src/parse parseList)
# # message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

aux_source_directory(. DIR_SRCS)
add_executable(
	temple_test
	${DIR_SRCS}
	${SYSTEM_DIR}
	${GAMES_DIR}
	${MATH_DIR}
	${RESOURCE_DIR}
)
