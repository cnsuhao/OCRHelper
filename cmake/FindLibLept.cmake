# - Find liblept
# Find the native LIBDL includes and library

# LIBLEPT_FOUND       		- True if libdl found
# LIBLEPT_STATIC_FOUND		- System has static libdl.a
# LIBLEPT_LIBRARIES   		- List of libraries when using libdl
# LIBLEPT_STATIC_LIBRARIES 	- The static libdl library
# LIBLEPT_HEADERS 		- Where to find dlfcn.h, etc

set( LIBLEPT_NAMES lept liblept )
find_library( LIBLEPT_LIBRARIES NAMES ${LIBLEPT_NAMES} )

if( ${LIBLEPT_LIBRARIES} MATCHES "NOTFOUND" )
  set( LIBLEPT_FOUND FALSE CACHE INTERNAL "" )
  message( STATUS "liblept.so library not found." )
  unset( LIBLEPT_LIBRARIES )
else()
  set( LIBLEPT_FOUND TRUE CACHE INTERNAL "" )
  message( STATUS "Found dynamic leptonica library: ${LIBLEPT_LIBRARIES}" )
endif()

set( OLD_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES} )
set( CMAKE_FIND_LIBRARY_SUFFIXES ".a" )
find_library( LIBLEPT_STATIC_LIBRARIES NAMES ${LIBLEPT_NAMES} )
set( CMAKE_FIND_LIBRARY_SUFFIXES ${OLD_SUFFIXES} )

if( ${LIBLEPT_STATIC_LIBRARIES} MATCHES "NOTFOUND")
  set(LIBLEPT_STATIC_FOUND FALSE CACHE INTERNAL "")
  message( STATUS "liblept.a library not found." )
  unset( LIBLEPT_STATIC_LIBRARIES )
else()
  set( LIBLEPT_STATIC_FOUND TRUE CACHE INTERNAL "" )
  message( STATUS "Found static leptonica library: ${LIBLEPT_STATIC_LIBRARIES}" )
endif()

find_path( LIBLEPT_HEADERS allheaders.h PATH_SUFFIXES leptonica)

MARK_AS_ADVANCED( LIBLEPT_LIBRARIES LIBLEPT_STATIC_LIBRARIES LIBLEPT_HEADERS )