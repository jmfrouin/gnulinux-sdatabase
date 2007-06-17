PROJECT(sdatabase)

INCLUDE(FindDoxygen)
INCLUDE(FindLATEX)
INCLUDE(FindUnixCommands)

ADD_DEFINITIONS(-g -DLEAK_DETECTOR -DDEBUG -Isrc -Wall -MD `wx-config --cxxflags`)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

INCLUDE_DIRECTORIES(AFTER SYSTEM .)

SET(folder engine files interface leak log plugins)

FOREACH(fold ${folder})
	ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

ADD_EXECUTABLE(sdatabase engine files interface leak log plugins)
