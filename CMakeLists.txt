cmake_minimum_required(VERSION 3.5.0)
project(CountRice VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)

add_executable(CountRice main.cpp)

target_link_libraries(CountRice ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



