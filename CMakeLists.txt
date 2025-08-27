# CMakeList.txt : CMake project for TEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TEngine")

add_library(TEngine
"src_new/tengine/Logger.h"
"src_new/tengine/Resourcer.h"
"src_new/tengine/SceneManager.h"
"src_new/tengine/Scene.h"
"src_new/tengine/Logger.cpp"
"src_new/tengine/Resourcer.cpp"
"src_new/tengine/SceneManager.cpp"
"src_new/tengine/Scene.cpp"
 "src_new/tutilities/RaylibVector2Hash.h" "src_new/tutilities/RaylibVector2Operators.h" "include/TPhysics.h" "src/physics/System.h" "src/physics/System.cpp" "src/physics/RigidBody.h" "src/physics/Affector.h" "src/physics/Affector.cpp" "src/physics/Hitbox.h" "src/physics/Hitbox.cpp" "src/physics/ForceVector.h" "src/physics/ForceVector.cpp" "src/physics/FreeBody.h" "src/physics/FreeBody.cpp" "src/physics/Collisions.cpp" "src/physics/Collisions.h" "src/physics/RigidStatic.h" "src/physics/RigidStatic.cpp"
        src_new/tengine/TObject.h
        src_new/tengine/TModule.cpp
        src_new/tengine/TModule.h
        src_new/tphysics/TPhysicsRigidBodyModule.cpp
        src_new/tphysics/TPhysicsRigidBodyModule.h
        src_new/tphysics/ForceVector.cpp
        src_new/tphysics/ForceVector.h
        src_new/tengine/TPoly.cpp
        src_new/tengine/TPoly.h
        src_new/tphysics/Collider.cpp
        src_new/tphysics/Collider.h
)

target_include_directories(TEngine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS TEngine DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)


# Add source to this project's executable.
# add_executable (TEngine "src/Logger.cpp" "src/Logger.h" "src/Resourcer.cpp" "src/Resourcer.h" "src/Scene.cpp" "src/Scene.h" "src/SceneManager.cpp" "src/SceneManager.h" "include/TEngine.h")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET TEngine PROPERTY CXX_STANDARD 20)
#endif()

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