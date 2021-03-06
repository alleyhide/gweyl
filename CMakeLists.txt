#
# @file CMakeLists.txt for gweyl
# @author ALIKAWA Hidehisa <alleyhide@gmail.com>
# @date 2018/04/30
# Released under the MIT license
#

cmake_minimum_required (VERSION 3.7.2)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O0 -g -std=c++14")

set(CMAKE_BUILD_TYPE Debug)

# gweyl
project (gweyl)

include_directories("${PROJECT_BINARY_DIR}")




# sub directories
#include_directories("${PROJECT_SOURCE_DIR}/CartanMatrix")

add_subdirectory(NumberVector)
add_subdirectory(Cartan)
add_subdirectory(CartanMatrix)
add_subdirectory(VectorRootSpace)
add_subdirectory(IrreducibleRepresentation)
add_subdirectory(Trace)

# dependencies
target_link_libraries(VectorRootSpace INTERFACE NumberVector)
target_link_libraries(IrreducibleRepresentation INTERFACE VectorRootSpace Cartan CartanMatrix)

add_library(gweyl SHARED "")

target_link_libraries (gweyl NumberVector Cartan CartanMatrix Trace VectorRootSpace IrreducibleRepresentation)

install (TARGETS gweyl LIBRARY DESTINATION lib)
install (FILES "gweyl.hpp" DESTINATION include)


# installer package

include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${gweyl_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${gweyl_VERSION_MINOR}")
#set (CPACK_GENERATOR "DEB")
#set (CPACK_DEBIAN_PACKAGE_MAINTAINEWR "Alikawa Hidehisa")
include (CPack)

#
# test
#  The tests are in test/
#
enable_testing()
add_subdirectory(test)


