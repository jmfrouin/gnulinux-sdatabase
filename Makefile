INCLUDEDIRS = -Isrc

CXX = $(shell wx-config --cxx)
CXXFLAGS = -g -DLEAK_DETECTOR -DDEBUG $(INCLUDEDIRS)
#CXXFLAGS = -DVERBOSE -Wall 
EXEC = sdatabase

#Debian specific stuff
DESTDIR=
BINDIR=/usr/bin

all:    $(EXEC)

# ------------------------------------------------------------------------------------------------------------------------------------------------
# GFX Interface
# ------------------------------------------------------------------------------------------------------------------------------------------------
interface.o:	src/interface/interface.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
	
sdatabase.o:	src/interface/sdatabase.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
	
edit_dialog.o:	src/interface/edit_dialog.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
	
find_dialog.o:	src/interface/find_dialog.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
	
new_table_dialog.o:	src/interface/new_table_dialog.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

tableview.o:	src/interface/tableview.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

file_explorer.o:	src/interface/file_explorer.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

# ------------------------------------------------------------------------------------------------------------------------------------------------
#  Leak detector
# ------------------------------------------------------------------------------------------------------------------------------------------------
memory_manager.o:	src/leak/memory_manager.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
# Test
memorytest.o:	memorytest.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
	
# ------------------------------------------------------------------------------------------------------------------------------------------------
#  Logs
# ------------------------------------------------------------------------------------------------------------------------------------------------
ilog.o:		src/log/ilog.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

filelog.o:	src/log/filelog.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

# ------------------------------------------------------------------------------------------------------------------------------------------------
#  Performance manager
# ------------------------------------------------------------------------------------------------------------------------------------------------
dummy.o:	src/performance/dummy.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

performance_analysis.o:	src/performance/performance_analysis.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<
# Test
test_perf.o:	src/performance/test_perf.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

# ------------------------------------------------------------------------------------------------------------------------------------------------
#  Main engine
# ------------------------------------------------------------------------------------------------------------------------------------------------
settings_manager.o:	src/engine/settings_manager.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

manager.o:	src/engine/manager.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

tools.o:	src/engine/tools.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

# ------------------------------------------------------------------------------------------------------------------------------------------------
#  Files plugins
# ------------------------------------------------------------------------------------------------------------------------------------------------
xmlfile.o:	src/files/xmlfile.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

csvfile.o:	src/files/csvfile.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

ifile.o:	src/files/ifile.cpp
	$(CXX) -c `wx-config --cxxflags` $(CXXFLAGS) -o $@ $<

# ------------------------------------------------------------------------------------------------------------------------------------------------
#  Code injection
# ------------------------------------------------------------------------------------------------------------------------------------------------
code_injecter.o:	src/injection/code_injecter.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

inject.o:	src/injection/inject.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

dummy2.o:	src/injection/dummy.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

main2.o:	src/injection/main.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

bob.o:
	./inject2.sh	
	
# ------------------------------------------------------------------------------------------------------------------------------------------------
# Doxygen documentation
# ------------------------------------------------------------------------------------------------------------------------------------------------
doxygen: 
	@doxygen sdatabase.dox
	@echo "[MAK] : Writing Documentation"
	
# ------------------------------------------------------------------------------------------------------------------------------------------------

$(EXEC):	performance_analysis.o ilog.o memory_manager.o settings_manager.o\
		tools.o manager.o tableview.o file_explorer.o new_table_dialog.o interface.o \
		sdatabase.o edit_dialog.o find_dialog.o xmlfile.o ifile.o csvfile.o
	$(CXX) -o $@ $^ `wx-config --libs`

# ------------------------------------------------------------------------------------------------------------------------------------------------
# Test 
# ------------------------------------------------------------------------------------------------------------------------------------------------
leak: filelog.o memory_manager.o memorytest.o
	$(CXX) -o $@ $^

test_perf:	test_perf.o dummy.o performance_analysis.o
	$(CXX) -o $@ $^ 

inject:	inject.o code_injecter.o
	$(CXX) -o $@ $^

test_inject: main2.o dummy2.o bob.o
	$(CXX) -o $@ $^
 
# ------------------------------------------------------------------------------------------------------------------------------------------------
clean: 
	rm -f _* *.s *.o $(EXEC) leak test_perf inject test_inject

realclean: clean
	rm -rf $(EXEC) doc/html/ doc/latex/
	
#Debian stuff
install:
	install -d -m 0755 -o root -g root $(DESTDIR)/$(BINDIR)
	install -m 0755 -o root -g root $(EXEC)  $(DESTDIR)/$(BINDIR)
# ------------------------------------------------------------------------------------------------------------------------------------------------
