#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(RUNTIME_SRCS_OS_INTERFACE_BASE
  ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
  ${CMAKE_CURRENT_SOURCE_DIR}/metrics_library.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/metrics_library.h
  ${CMAKE_CURRENT_SOURCE_DIR}/ocl_reg_path.h
  ${CMAKE_CURRENT_SOURCE_DIR}/os_inc_base.h
  ${CMAKE_CURRENT_SOURCE_DIR}/performance_counters.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/performance_counters.h
)

target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${RUNTIME_SRCS_OS_INTERFACE_BASE})
set_property(GLOBAL PROPERTY RUNTIME_SRCS_OS_INTERFACE_BASE ${RUNTIME_SRCS_OS_INTERFACE_BASE})
add_subdirectories()
