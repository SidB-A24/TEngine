# CMakeList.txt : CMake project for TEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TEngine")

# Add source to this project's executable.
add_executable (TEngine  "tengine/Logger.h" "tengine/Logger.cpp" "tengine/Resourcer.h" "tengine/Resourcer.cpp" "tengine/SceneManager.h" "tengine/SceneManager.cpp" "tengine/Scene.h" "tengine/Scene.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
# Dependencies
include(FetchContent)
set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

# Removes examples
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")


#Fetches content of raylib and adds to the project files
FetchContent_MakeAvailable(raylib)

#Links libraries to the project
target_link_libraries(${PROJECT_NAME} raylib)