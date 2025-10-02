cmake_minimum_required(VERSION 3.14)
project(housing-lottery)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(housing)
target_sources(housing
   PRIVATE
      housing.cpp
   PUBLIC
      housing.h
)
target_include_directories(housing
   PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}
)

enable_testing()
add_subdirectory(tests)

