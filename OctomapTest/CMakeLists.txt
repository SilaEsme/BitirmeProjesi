cmake_minimum_required(VERSION 3.0.0)
project(OctomapTest VERSION 0.1.0)


include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(OctomapTest ${SOURCES})

#Octomap Library
find_package(octomap REQUIRED)
include_directories(${OCTOMAP_INCLUDE_DIRS})
link_libraries(${OCTOMAP_LIBRARIES})
target_link_libraries(OctomapTest ${OCTOMAP_LIBRARIES})

#PCL Library
find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
target_link_libraries (OctomapTest ${PCL_LIBRARIES})

include(CTest)
enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
