
cmake_minimum_required(VERSION 2.8.9)

project (Summitto)

find_package(ZLIB)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/zlib/1.2.11)
message("asda" ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(summitto main.cpp encode.h VATParser.h VATParser.cpp)

target_link_libraries(summitto   ${CMAKE_CURRENT_SOURCE_DIR}/lib/zlib/1.2.11/x64/vc14/zlibstaticd.lib ${CMAKE_CURRENT_SOURCE_DIR}/lib/zlib/1.2.11/x64/vc14/zlibstatic.lib
)


