cmake_minimum_required(VERSION 3.17.2)

project(CComplexVector)

set(VECTOR_SRC main.cpp complexnumber.cpp complexvector.cpp complexvector1.cpp complexvector0.cpp scan.cpp autotest.cpp)
set(VECTOR_HDR complexnumber.h complexvector.hpp complexvector1.hpp complexvector0.hpp factory.h factoryhori.h factoryvirt.h)

add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

#target_link_libraries(${PROJECT_NAME} vector)
install (TARGETS "${PROJECT_NAME}" DESTINATION bin)	#$(CMAKE_INSTALL_PREFIX)/bin
install (FILES "${VECTOR_SRC}" DESTINATION src)  	#$(CMAKE_INSTALL_PREFIX)/src
install (FILES "${VECTOR_HDR}" DESTINATION hdr)  	#$(CMAKE_INSTALL_PREFIX)/hdr


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g -Og")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
