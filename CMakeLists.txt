# CMakeList.txt : CMake project for UAVControlSim, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.22)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Enable Hot Reload for MSVC compilers if supported.
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project (UAVControlSim)

#add_subdirectory(library/FTXUI)
# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/arthursonzogni/ftxui.git
  GIT_TAG        v5.0.0
  GIT_PROGRESS   TRUE
  GIT_SHALLOW    TRUE
  EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(ftxui)
# ------------------------------------------------------------------------------



# Add source to this project's executable.
add_executable ("${CMAKE_PROJECT_NAME}" "UAVControlSim.cpp")

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES} )
#set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  
endif()

# TODO: Add tests and install targets if needed.
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include/")

#target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE ftxui)
target_link_libraries( "${CMAKE_PROJECT_NAME}"
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component  # Not needed for this example.
)

