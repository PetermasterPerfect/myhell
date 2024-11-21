# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.15 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(myhell)

if(NOT EXISTS ${PROJECT_SOURCE_DIR}/antlr4.jar)
	file(
	  DOWNLOAD https://www.antlr.org/download/antlr-4.13.0-complete.jar
	  EXPECTED_HASH SHA256=bc6f4abc0d225a27570126c51402569f000a8deda3487b70e7642840e570e4a6
	  SHOW_PROGRESS
	  ${PROJECT_SOURCE_DIR}/antlr4.jar
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

set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/antlr4.jar)
find_package(ANTLR REQUIRED)

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${PROJECT_SOURCE_DIR}/Hades.g4 -o ${PROJECT_SOURCE_DIR}/build)

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${PROJECT_SOURCE_DIR}/AssHades.g4 -o ${PROJECT_SOURCE_DIR}/build)

execute_process(
	COMMAND java -jar ${ANTLR_EXECUTABLE} -no-listener -visitor -Dlanguage=Cpp ${PROJECT_SOURCE_DIR}/SentenceHades.g4 -o ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/build)

file(GLOB SOURCE
	${PROJECT_SOURCE_DIR}/*.cpp
	${PROJECT_SOURCE_DIR}/*.h)

file(GLOB BUILD
	${PROJECT_SOURCE_DIR}/build/*.cpp
	${PROJECT_SOURCE_DIR}/build/*.h)


# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

# add generated grammar to demo binary target
add_executable(myhell ${SOURCE} ${BUILD})
target_link_libraries(myhell antlr4_static)
