project( supplier_ocr LANGUAGES CXX )

cmake_minimum_required( VERSION 2.8 )
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )
set ( CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so" )
set ( CMAKE_BUILD_TYPE Debug )

find_package ( MySQLClient REQUIRED )
find_package ( Threads REQUIRED )
find_package ( LibDL REQUIRED )
find_package ( LibLept REQUIRED )

###############################################################################
## target definitions #########################################################
###############################################################################

file( GLOB_RECURSE SOURCES 	"${PROJECT_SOURCE_DIR}/main.cpp" 
							"${PROJECT_SOURCE_DIR}/src/*.cpp" )

add_executable(supplier_ocr ${SOURCES})

set_property( TARGET supplier_ocr PROPERTY CXX_STANDARD 11 )
set_property( TARGET supplier_ocr PROPERTY CXX_STANDARD_REQUIRED ON )

###############################################################################
## dependencies ###############################################################
###############################################################################

# POCO
set(POCO_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env") 
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR "${POCO_PREFIX}/lib")
set(POCO_LIBS 	"${POCO_LIB_DIR}/libPocoXML.so"
				"${POCO_LIB_DIR}/libPocoFoundation.so")

# DL
set(DL_PREFIX "/usr/lib/x86_64-linux-gnu/") 
set(DL_LIB_DIR "${DL_PREFIX}")
set(DL_LIBS "${DL_LIB_DIR}/libdl.so")

# OCR: ASPRISE (Depend: libdl.co)
set(ASPRISE_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env") 
set(ASPRISE_INCLUDE_DIR "${ASPRISE_PREFIX}/include")
set(ASPRISE_LIB_DIR "${ASPRISE_PREFIX}/lib")
set(ASPRISE_LIBS "${ASPRISE_LIB_DIR}/libaocr_x64.so")

# Leptonica
set(LEPT_PREFIX "/usr/local") 
set(LEPT_INCLUDE_DIR "${LEPT_PREFIX}/include")
set(LEPT_LIB_DIR "${LEPT_PREFIX}/lib")
set(LEPT_LIBS "${LEPT_LIB_DIR}/liblept.so")

# OCR: Tesseract (depend: leptonica)
set(TESSERACT_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env") 
set(TESSERACT_INCLUDE_DIR "${TESSERACT_PREFIX}/include")
set(TESSERACT_LIB_DIR "${TESSERACT_PREFIX}/lib")
set(TESSERACT_LIBS "${TESSERACT_LIB_DIR}/libtesseract.so")


include_directories(	${POCO_INCLUDE_DIR} 
			${ASPRISE_INCLUDE_DIR}
			${LEPT_INCLUDE_DIR}
			${TESSERACT_INCLUDE_DIR})

link_directories(	${POCO_LIB_DIR} 
			${DL_LIB_DIR} 
			${ASPRISE_LIB_DIR} 
			${LEPT_LIB_DIR}
			${TESSERACT_LIB_DIR})


if ( MYSQLCLIENT_STATIC_LIBRARIES )
	message ( STATUS "Linking static with ${MYSQLCLIENT_STATIC_LIBRARIES}" )
	set ( "LIBMARIADB" ${MYSQLCLIENT_STATIC_LIBRARIES} )
else ( MYSQLCLIENT_STATIC_LIBRARIES )
	message ( STATUS "Linking dynamic with ${MYSQLCLIENT_LIBRARIES}" )
	set ( "LIBMARIADB" ${MYSQLCLIENT_LIBRARIES} )
endif()


target_link_libraries(	supplier_ocr 
			${POCO_LIBS} 
			${DL_LIBS} 
			${ASPRISE_LIBS} 
			${LEPT_LIBS}
			${TESSERACT_LIBS})

