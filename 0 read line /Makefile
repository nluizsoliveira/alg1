BINARY=binary
SOURCES=main.c readline.c memory.c 
INCLUDES=.

all: clean compile clean

compile:
	@gcc -o $(BINARY) $(SOURCES) -I$(INCLUDES)

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./binary

zip:
	zip -r binary.zip *.c *.h Makefile