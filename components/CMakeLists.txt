cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/IEEE_754_Representations)

add_executable(untitled main.cpp
        services/IEEE_754_Representation/components/subunitary_mantissa.cpp
        services/IEEE_754_Representation/components/supraunitary_mantissa.cpp
        ui/console.cpp
        ui/console.h
        services/IEEE_754_Representation/utils/utils.cpp
        services/IEEE_754_Representation/utils/utils.h
)

