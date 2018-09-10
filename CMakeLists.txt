cmake_minimum_required (VERSION 3.12)
project (FranzFerdiandLib)

find_package( Boost 1.68 REQUIRED COMPONENTS )
find_package( GTest REQUIRED )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out )

file (GLOB  UNIT_TEST_FILES_CPP  unit_tests/*/*.cpp)

include_directories(${PROJECT_BINARY_DIR})

add_executable (unit_tests_exe    unit_tests/main.cpp ${UNIT_TEST_FILES_CPP})

target_link_libraries(unit_tests_exe ${GTEST_BOTH_LIBRARIES})
