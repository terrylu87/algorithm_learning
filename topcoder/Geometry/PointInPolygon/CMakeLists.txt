cmake_minimum_required (VERSION 2.6)

set (TARGET_NAME PointInPolygon)
set (GTEST_ENABLED ON)

project (Example)

set (Example_VERSION_MAJOR 1)
set (Example_VERSION_MINOR 0)

file(GLOB SRC
  "*.h"
  "*.cpp"
  )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  # /usr/local/include/
  )

add_executable(${TARGET_NAME} ${SRC})

if(GTEST_ENABLED)
  target_link_libraries(
    ${TARGET_NAME} gtest pthread
    )
endif(GTEST_ENABLED)