EXECUTABLE=randomise_m3u
CXX=g++
CXXFLAGS=-Wall -g
#LINKFLAGS=-m32
OBJ_FILES=main.o

$(EXECUTABLE): $(OBJ_FILES)
	g++ $(LINKFLAGS) $< -o $@

.PHONY: clean

clean:
	-rm $(EXECUTABLE) $(OBJ_FILES)
