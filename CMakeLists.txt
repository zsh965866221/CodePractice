cmake_minimum_required(VERSION 3.8)
project(Computer_Algorithms)

set(CMAKE_CXX_STANDARD 11)

set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "_r")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)

## 保留main文件，用以临时测试
add_executable(main main.cpp)

## for OJs
set(OJsDir OJs)
file(GLOB HiHoAPPS ${OJsDir}/hihoCoder/*.cpp)
foreach(sourcefile ${HiHoAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "hihoCoder-\\1" appname ${sourcefile})
    message(hihoCoder/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()
file(GLOB HiHoAPPS ${OJsDir}/LeetCode/*.cpp)
foreach(sourcefile ${HiHoAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "LeetCode-\\1" appname ${sourcefile})
    message(LeetCode/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()
file(GLOB utilsAPPS ${OJsDir}/Utils/*.cpp)
foreach(sourcefile ${utilsAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "Utils-\\1" appname ${sourcefile})
    message(Utils-/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()
file(GLOB othersAPPS ${OJsDir}/others/*.cpp)
foreach(sourcefile ${othersAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "Others-\\1" appname ${sourcefile})
    message(Utils-/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()
file(GLOB acmcoderAPPS ${OJsDir}/ACMCoder/*.cpp)
foreach(sourcefile ${acmcoderAPPS})
    STRING( REGEX REPLACE ".*/(.*).cpp$" "ACMCoder-\\1" appname ${sourcefile})
    message(Utils-/${appname})
    add_executable(${appname} ${sourcefile})
endforeach()

## for Introduction to Algorithms
set(ItODir Introduction-to-Algorithms)
