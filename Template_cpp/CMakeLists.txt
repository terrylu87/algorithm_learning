cmake_minimum_required (VERSION 2.6)

project (Example)

set (Example_VERSION_MAJOR 1)
set (Example_VERSION_MINOR 0)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  /usr/local/include/
  )
target_link_libraries(
  gtest
  )

add_executable(example main.cpp)