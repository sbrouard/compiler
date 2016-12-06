LEX=lex
YACC=bison
CFLAGS=-Wall
CC=gcc

all: clean parse

parse:grammar.c scanner.c expression_symbols.c
	$(CC) $(CFLAGS) -o $@ $^

grammar.c:grammar.y
	$(YACC) -t -d -o $@ --defines=grammar.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^

clean:
	rm -f grammar.c scanner.c parse grammar.tab.h *~
