CMAKE_MINIMUM_REQUIRED(VERSION 3.20 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(myhell)

set(SOURCES ${PROJECT_SOURCE_DIR}/src)

if(NOT EXISTS ${CMAKE_BINARY_DIR}/antlr4.jar)
	file(
	  DOWNLOAD https://www.antlr.org/download/antlr-4.13.0-complete.jar
	  EXPECTED_HASH SHA256=bc6f4abc0d225a27570126c51402569f000a8deda3487b70e7642840e570e4a6
	  SHOW_PROGRESS
	  ${CMAKE_BINARY_DIR}/antlr4.jar
	)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE ${CMAKE_BINARY_DIR}/antlr4.jar)
find_package(ANTLR REQUIRED)

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${SOURCES}/Hades.g4 -o ${CMAKE_BINARY_DIR})

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${SOURCES}/Arithmetic.g4 -o ${CMAKE_BINARY_DIR})

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${SOURCES}/AssHades.g4 -o ${CMAKE_BINARY_DIR})

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${SOURCES}/SentenceHades.g4 -o ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")

include_directories(${SOURCES})
include_directories(${CMAKE_BINARY_DIR})

file(GLOB SOURCE
	${SOURCES}/*.cpp
	${SOURCES}/*.h)

file(GLOB BUILD
	${CMAKE_BINARY_DIR}/*.cpp
	${CMAKE_BINARY_DIR}/*.h)


# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

# add generated grammar to demo binary target
add_executable(myhell ${SOURCE} ${BUILD})
target_link_libraries(myhell antlr4_static)
install(TARGETS myhell RUNTIME DESTINATION bin)
