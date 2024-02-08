cmake_minimum_required(VERSION 3.24)
project(client)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR /opt/homebrew/Cellar/boost/1.83.0/include)
set(Boost_LIBRARY_DIR /opt/homebrew/Cellar/boost/1.83.0/lib)
find_package(Boost 1.83.0 COMPONENTS system filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

add_executable(client main.cpp LivePlayClient.cpp LivePlayClient.h)
target_link_libraries(client ${Boost_LIBRARIES})
