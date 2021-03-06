# - Config file for the bamboo package
# It defines the following variables
#  BAMBOO32_INCLUDE_DIRS - include directories for bamboo
#  BAMBOO32_LIBRARY_DIRS - library directories for bamboo
#  BAMBOO32_LIBRARIES    - libraries to link against

# Compute paths
get_filename_component(BAMBOO32_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(BAMBOO32_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include/bamboo32")
set(BAMBOO32_LIBRARY_DIRS ${BAMBOO32_CMAKE_DIR})

# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET bamboo32 AND NOT BAMBOO32_BINARY_DIR)
  include("${BAMBOO32_CMAKE_DIR}/bamboo32-targets.cmake")
endif()

# These are IMPORTED targets created by Bamboo32Targets.cmake
set(BAMBOO32_LIBRARIES bamboo32)
