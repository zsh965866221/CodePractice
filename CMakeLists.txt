cmake_minimum_required(VERSION 3.8)
project(CodePractice)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH out)

file(GLOB HiHoAPPS hihoCoder/*.cpp)
foreach(sourcefile ${HiHoAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "hihoCoder-\\1" appname ${sourcefile})
    message(hihoCoder/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()

file(GLOB HiHoAPPS LeetCode/*.cpp)
foreach(sourcefile ${HiHoAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "LeetCode-\\1" appname ${sourcefile})
    message(LeetCode/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()

add_executable(main main.cpp)