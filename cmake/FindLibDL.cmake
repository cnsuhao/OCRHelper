# - Find libdl
# Find the native LIBDL includes and library

# LIBDL_FOUND       		- True if libdl found
# LIBDL_STATIC_FOUND		- System has static libdl.a
# LIBDL_LIBRARIES   		- List of libraries when using libdl
# LIBDL_STATIC_LIBRARIES 	- The static libdl library
# LIBDL_HEADERS 		- Where to find dlfcn.h, etc

set( LIBDL_NAMES dl libdl ltdl libltdl )
find_library( LIBDL_LIBRARIES NAMES ${LIBDL_NAMES} )

if( ${LIBDL_LIBRARIES} MATCHES "NOTFOUND" )
  set( LIBDL_FOUND FALSE CACHE INTERNAL "" )
  message( STATUS "libdl.so library not found." )
  unset( LIBDL_LIBRARIES )
else()
  set( LIBDL_FOUND TRUE CACHE INTERNAL "" )
  message( STATUS "Found dynamic libdl library: ${LIBDL_LIBRARIES}" )
endif()

set( OLD_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES} )
set( CMAKE_FIND_LIBRARY_SUFFIXES ".a" )
find_library( LIBDL_STATIC_LIBRARIES NAMES ${LIBDL_NAMES} )
set( CMAKE_FIND_LIBRARY_SUFFIXES ${OLD_SUFFIXES} )

if( ${LIBDL_STATIC_LIBRARIES} MATCHES "NOTFOUND")
  set(LIBDL_STATIC_FOUND FALSE CACHE INTERNAL "")
  message( STATUS "libdl.a library not found." )
  unset( LIBDL_STATIC_LIBRARIES )
else()
  set( LIBDL_STATIC_FOUND TRUE CACHE INTERNAL "" )
  message( STATUS "Found static libdl library: ${LIBDL_STATIC_LIBRARIES}" )
endif()

find_path( LIBDL_HEADERS dlfcn.h )

MARK_AS_ADVANCED( LIBDL_LIBRARIES LIBDL_STATIC_LIBRARIES LIBDL_HEADERS )