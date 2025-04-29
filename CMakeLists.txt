# CMakeList.txt : CMake project for UAVControlSim, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

project (UAVControlSim)

# Add source to this project's executable.
add_executable ("${CMAKE_PROJECT_NAME}" "UAVControlSim.cpp")

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES} )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include/")