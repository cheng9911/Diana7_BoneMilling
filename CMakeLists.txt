cmake_minimum_required(VERSION 3.10)

project(rocos_test)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(DianaApi/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/DianaApi/bin)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/DianaApi/lib)
# find_library(DianaApi_LIBRARY NAMES DianaApi BasicSdk GenericAlgorithm ToolSdk xml2 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/DianaApi/lib  ${CMAKE_CURRENT_SOURCE_DIR}/DianaApi/bin)
find_package(Threads)
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(orocos_kdl REQUIRED)

set( List_Cpp
main
test
sensor
drag
test_servoL
  )
set(LIST ${List_Cpp} )
foreach(list ${LIST})

  add_executable(${list} src/${list}.cpp  )
  target_include_directories(${list} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
  target_link_libraries(${list} PUBLIC  DianaApi BasicSdk GenericAlgorithm ToolSdk xml2 Boost::system Boost::thread Threads::Threads orocos-kdl)

endforeach()

