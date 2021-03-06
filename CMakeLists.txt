# Copyright (C) 2018 Johann Lee <me@qinka.pro>
#
# This file is part of Haskell-FAI
#
# qinka-cs is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# qinka-cs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Haskell-FAI. If not, see <http://www.gnu.org/licenses/>.
#

# CMake 3.3
cmake_minimum_required(VERSION 3.3)

# Qinka Computing Subprogram
project(qinkacs VERSION 0.1.0.0)

## setting up the c++-11 and c-11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD   11)

add_definitions(-D_INNER_QCS_)

# OPT FLAG
if (${ENABLE_O3})
    if     ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # using Clang
        message("Use Clang")
        set(OPT_FLAG " -O3 ")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
        # using GCC
        message("Use Apple Clang")
        set(OPT_FLAG " -O3 ")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        # using GCC
        message("Use GCC")
        set(OPT_FLAG " -O3 ")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "PGI")
        # using PGI
        message("Use PGI")
        set(OPT_FLAG " -O3 ")
        if(ACC_TARGET)
            message("Use target ${ACC_TARGET}")
            set(ACC_TARGET_FLAG "-ta=${ACC_TARGET}")
        endif()
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        # using Visual Studio C++
        set(OPT_FLAG " /O2 ")
    endif()

    set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS}   ${OPT_FLAG}")
    set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${OPT_FLAG}")
else()
    add_definitions(-D__DISABLEO3__)
endif()


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

## Accelerate Backend
# OpenMP
option(ENABLE_OPENMP         "Enable OpenMP"                       Off)
option(ENABLE_OPENMP_TARGET  "Enable OpenMP using target"          Off)
# OpenACC
option(ENABLE_OPENACC        "Enable OpenACC"                      Off)
option(ENABLE_OPENACC_DRVPTR "Enable OpenACC using device pointer" Off)
## TARGET
set(ACC_TARGET "" CACHE STRING "The accelerate target platform")

## Can not enable OpenMP and OpenAcc at the same time.
if(${ENABLE_OPENMP} AND ${ENABLE_OPENACC})
    message(FATAL_ERROR "Can not enable OpenMP and OpenAcc at the same time!")
endif()


## OpenMP
if(ENABLE_OPENMP)
    FIND_PACKAGE(OpenMP REQUIRED)
    if(OPENMP_FOUND)
        message("OPENMP FOUND")
        set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
        set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
        message("Enable OpenMP")
        add_definitions(-D_OMP_ENABLE_)
        if(ENABLE_OPENMP_TARGET)
	        set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS} -omptargets=${OPENMP_TARGET}")
            add_definitions(-D_OMP_TARGET_=${ACC_TARGET})
            message("Using target(${ACC_TARGET})")
        endif()
    endif()
endif()

## OpenACC
if(ENABLE_OPENACC)
    find_package(OpenACC REQUIRED)
    if(${OpenACC_C_FOUND} AND ${OpenACC_CXX_FOUND})
        message("OpenACC Found")
        set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS} ${OpenACC_C_FLAGS} ${ACC_TARGET_FLAG}")
        set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${OpenACC_CXX_FLAGS} ${ACC_TARGET_FLAG}")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
        add_definitions(-D_OACC_ENABLE_)
        message("Enable OpenACC")
        if(ENABLE_OPENACC_DRVPTR)
            message("Using drive pointer with OpenACC")
            add_definitions(-D_OACC_DRVPTR_)
        endif()
        FIND_PACKAGE(CUDA REQUIRED)
    endif()
endif()

aux_source_directory("${PROJECT_SOURCE_DIR}/source" SRC_FILES)

configure_file (
    "${PROJECT_SOURCE_DIR}/include/config_gen.h.in"
    "${PROJECT_BINARY_DIR}/include/config_gen.h"
    )
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}/include")

add_library(qinka-cs SHARED ${SRC_FILES})
if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "PGI") AND ENABLE_OPENACC)
    message("Link with cuda's library")
    target_link_libraries(qinka-cs ${CUDA_curand_LIBRARY} ${CUDA_LIBRARIES})
endif()
if(APPLE AND ENABLE_OPENMP)
    message("In Apple macOS with OpenMP")
    target_link_libraries(qinka-cs omp)
endif()
    

### install
file (GLOB QCS_PUB_HEADS "${PROJECT_SOURCE_DIR}/include/qinka_cs/*/*.h")
variable_watch(QCS_PUB_HEADS)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/qinka_cs/" DESTINATION "include/qinka_cs" COMPONENT dev
        FILES_MATCHING PATTERN "*.h")

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(LIB_INS_PATH bin)
else()
    set(LIB_INS_PATH lib)
endif()

install(TARGETS qinka-cs
    ARCHIVE       DESTINATION "lib"           COMPONENT dev
    RUNTIME       DESTINATION ${LIB_INS_PATH} COMPONENT runtime
    LIBRARY       DESTINATION "lib"           COMPONENT dev
)



### Testing
option(BUILD_TESTS "Enable test" Off)

if(${BUILD_TESTS})
    message("Enable testing")
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    aux_source_directory("${PROJECT_SOURCE_DIR}/test" TEST_FILES)
    add_executable(qinka-cs-test ${TEST_FILES})
    target_link_libraries(qinka-cs-test ${GTEST_BOTH_LIBRARIES} qinka-cs)
    if(NOT(CMAKE_SYSTEM_NAME MATCHES "Windows"))
        target_link_libraries(qinka-cs-test pthread)
    endif()
    add_test(QCS_TEST qinka-cs-test)
endif()

## Packaing
set(CPACK_PACKAGE_NAME "qinka-cs")
set(CPACK_GENERATOR "TXZ;STGZ;TGZ;TZ;ZIP")  
set(CPACK_SOURCE_GENERATOR "DEB")  
set(CPACK_PACKAGE_VENDOR "Johann Lee <me@qinka.pro>")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Johann Lee <me@qinka.pro>")
set(CPACK_PACKAGE_DESCRIPTION "A set of subprogram of math.")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY, "An example of QCS")
set(CPACK_RESOURCE_FILE_LICENSE ${PROJECT_SOURCE_DIR}/LICENSE)
# Debian
SET(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_SOURCE "qinka-cs")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6), llibgcc1 (>= 1:3.4.2-12), libstdc++6 (>= 5)")
set(CPACK_DEBIAN_DEV_PACKAGE_DEPENDS "${CPACK_DEBIAN_PACKAGE_DEPENDS}, qinka-cs-runtime (>= 0.1.1)")
set(CPACK_DEBIAN_RUNETIME_PACKAGE_SECTION "runtime")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION_SUMMARY "Qinka Computing Subprograms.")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Qinka Computing Subprograms. [TODO]")
include(CPack)

# Gen changelog for debian
configure_file (
    "${PROJECT_SOURCE_DIR}/debian/changelog.in.in"
    "${PROJECT_SOURCE_DIR}/debian/changelog.in"
    )