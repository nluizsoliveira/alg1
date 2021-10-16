BINARY=trab4
SOURCES=readline.c numbers.c main.c
INCLUDES=.

all: clean compile clean

compile:
	@gcc -o $(BINARY) $(SOURCES) -I$(INCLUDES)

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./trab4

zip:
	zip -r trab4.zip *.c *.h Makefile