cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/IEEE_754_Representations)

add_executable(untitled main.cpp
        services/IEEE_754_Representation/subunitary_mantissa.cpp
        services/IEEE_754_Representation/supraunitary_mantissa.cpp
        services/services.cpp
)

# list(APPEND SOURCES services/OtherSourceFile.cpp)
