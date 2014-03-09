MAIN = 	src/Main.o\
	src/Map.o\
	src/Player.o\
	src/Screen.o

all: $(MAIN)
	g++ -o client $(MAIN) -lSDL -lSDL_image -lSDL_mixer

.PHONY: clean cleanall

clean:
	find src/ | egrep '(\.o|\.so)$\' | xargs rm
	rm client
