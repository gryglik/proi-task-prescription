cmake_minimum_required(VERSION 3.11.0)
project(prescription VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY      https://github.com/google/googletest.git
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

set(PROJECT_SOURCES prescription.cpp prescription.h date.h date.cpp patient.h patient.cpp)

add_executable(main.exe main.cpp ${PROJECT_SOURCES})

add_executable(testGoogle testGoogle.cpp ${PROJECT_SOURCES})
target_link_libraries(testGoogle PUBLIC gtest_main)
