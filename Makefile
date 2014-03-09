MAIN = 	src/Main.o\
	src/Map.o\
	src/Player.o\
	src/Screen.o

UTILS = src/utils/genmap_test.o

all: $(MAIN) $(UTILS)
	g++ -o client $(MAIN) -lSDL -lSDL_image -lSDL_mixer
	g++ -o src/utils/Generate_Test_Map $(UTILS)

.PHONY: clean cleanall

clean:
	find src/ | egrep '(\.o|\.so)$\' | xargs rm
	rm client
