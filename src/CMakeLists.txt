PROJECT(sdatabase)

INCLUDE(FindDoxygen)
INCLUDE(FindLATEX)
INCLUDE(FindUnixCommands)
INCLUDE(FindwxWidgets)

ADD_DEFINITIONS(-g -DLEAK_DETECTOR -DDEBUG -Isrc -Wall -MD `wx-config --cxxflags`)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/config.h.cmake ${CMAKE_BINARY_DIR}/config.h)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

INCLUDE_DIRECTORIES(AFTER SYSTEM ${CMAKE_BINARY_DIR} .)

SET(folder engine files leak log performance plugins tools)

FOREACH(fold ${folder})
	ADD_SUBDIRECTORY(${fold})
ENDFOREACH(fold ${folder})

ADD_EXECUTABLE(sdatabase interface/sdatabase.cpp interface/edit_dialog.cpp interface/file_explorer.cpp interface/find_dialog.cpp interface/interface.cpp interface/new_table_dialog.cpp interface/tableview.cpp)
TARGET_LINK_LIBRARIES(sdatabase engine files leak log performance plugins tools `wx-config --libs`)
