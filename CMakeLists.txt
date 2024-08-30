cmake_minimum_required(VERSION 3.10)

project(Jlox
	VERSION 0.1
	LANGUAGES C CXX
)

file(GLOB SRC_FILES src/*.cpp)
file(GLOB HDR_FILES src/*.h)

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES} ${HDR_FILES})

message(${SRC_FILES})
message(${HDR_FILES})