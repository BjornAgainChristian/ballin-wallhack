MAIN = 	src/Main.o\
	src/Map.o\
	src/Player.o\
	src/Screen.o

UTILS = src/utils/genmap_test.o

all: $(MAIN)
	g++ -o client $(MAIN) -Wall -O2 -lSDL -lSDL_image -lSDL_mixer

utils: $(UTILS)
	g++ -o src/utils/Generate_Test_Map $(UTILS)

.PHONY: clean cleanall

clean:
	find src/ | egrep '(\.o|\.so)$\' | xargs rm
	rm client
