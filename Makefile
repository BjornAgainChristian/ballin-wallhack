MAIN = 	src/Main.o\
	src/Map.o\
	src/Player.o\
	src/Screen.o

BIGMAP 	= src/utils/genmap_test.o
SMALLMAP= src/utils/genmap_small_test.o

all: $(MAIN)
	g++ -o client $(MAIN) -Wall -O2 -lSDL -lSDL_image -lSDL_mixer

utils: $(BIGMAP) $(SMALLMAP)
	g++ -o src/utils/Generate_Test_Map $(BIGMAP)
	g++ -o src/utils/Generate_Small_Map $(SMALLMAP)

.PHONY: clean cleanall

clean:
	find src/ | egrep '(\.o|\.so)$\' | xargs rm
	rm client

cleanutils:
	rm src/utils/Generate_Test_Map
	rm src/utils/Generate_Small_Map
