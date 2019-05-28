cmake_minimum_required(VERSION 3.1)
project(voxels)

option(TBB_BUILD_STATIC OFF)
option(TBB_BUILD_TBBMALLOC OFF)
option(TBB_BUILD_TBBMALLOC_PROXY OFF)
option(TBB_BUILD_TESTS OFF)
add_subdirectory(ThirdParty/tbb)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif()

include_directories(include/
                    ThirdParty/glm/glm/
                    ThirdParty/tbb/include/tbb/)

file(GLOB PROJECT_HEADERS include/*.hpp src/*.hpp)
file(GLOB PROJECT_SOURCES src/*.cpp)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          README.md
                         .gitignore)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_library(voxels SHARED ${PROJECT_SOURCES})
set_target_properties(voxels PROPERTIES PUBLIC_HEADER include/Voxels.h)

add_definitions(-DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
target_link_libraries(${PROJECT_NAME} tbb)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
