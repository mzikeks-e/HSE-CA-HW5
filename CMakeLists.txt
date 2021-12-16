cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Task5 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS -pthread)

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set(SOURCE_FILES
        code/AsyncBuffer.h
        code/ConsumerAllChecker.h
        code/ConsumerSharpener.h
        code/ConsumerStraightChecker.h
        code/Generator.h
        code/Machine.h
        code/Pin.h
        code/AsyncBuffer.cpp
        code/ConsumerAllChecker.cpp
        code/ConsumerSharpener.cpp
        code/ConsumerStraightChecker.cpp
        code/Generator.cpp
        code/Machine.cpp
        code/Pin.cpp

        code/Task5.cpp
)
add_executable(Task5 ${SOURCE_FILES})

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")