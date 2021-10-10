BINARY=trab3
SOURCES=readline.c card.c deck.c main.c
INCLUDES=.

all: clean compile clean

compile:
	@gcc -o $(BINARY) $(SOURCES) -I$(INCLUDES)

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./trab3

zip:
	zip -r trab3.zip *.c *.h Makefile