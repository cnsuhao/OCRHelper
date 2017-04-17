cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(ocr VERSION 0.1 LANGUAGES CXX)

###############################################################################
## target definitions #########################################################
###############################################################################

file(GLOB SOURCES
 	main.cpp)

add_executable(ocr ${SOURCES})
set(CMAKE_BUILD_TYPE Debug)

###############################################################################
## compiler definitions########################################################
###############################################################################

set_property(TARGET ocr PROPERTY CXX_STANDARD 11)
set_property(TARGET ocr PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################

# POCO
set(POCO_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env") 
set(POCO_INCLUDE_DIR"${POCO_PREFIX}/include")
set(POCO_LIB_DIR "${POCO_PREFIX}/lib")
set(POCO_LIBS "${POCO_LIB_DIR}/libPocoXML.so")

# DL
set(DL_PREFIX "/usr/lib/x86_64-linux-gnu/") 
set(DL_LIB_DIR "${DL_PREFIX}")
set(DL_LIBS "${DL_LIB_DIR}/libdl.so")

# OCR: ASPRISE (Depend: libdl.co
set(ASPRISE_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env") 
set(ASPRISE_INCLUDE_DIR"${ASPRISE_PREFIX}/include")
set(ASPRISE_LIB_DIR "${ASPRISE_PREFIX}/lib")
set(ASPRISE_LIBS "${ASPRISE_LIB_DIR}/libaocr_x64.so")


include_directories(${POCO_INCLUDE} ${ASPRISE_INCLUDE})
link_directories(${POCO_LIB_DIR} ${DL_LIB_DIR} ${ASPRISE_LIB_DIR})
target_link_libraries(ocr ${POCO_LIBS} ${DL_LIBS} ${ASPRISE_LIBS})

