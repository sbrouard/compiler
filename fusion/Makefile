LEX=lex
YACC=bison
CFLAGS=-Wall
CC=gcc

all: clean parse

tests: clean parse test_for test_for_infinite_loop test_while test_if

declarator:
	./parse tests/declarator.c && touch tests/declarator.ll && cat test_llvm.ll > tests/declarator.ll

test_for: 
	./parse tests/test_for.c && touch tests/test_for.ll && cat test_llvm.ll > tests/test_for.ll 

test_for_infinite_loop:
	./parse tests/test_for_infinite_loop.c && touch tests/test_for_infinite_loop.ll && cat test_llvm.ll > tests/test_for_infinite_loop.ll

test_while:
	 ./parse tests/test_while.c && touch tests/test_while.ll && cat test_llvm.ll > tests/test_while.ll

test_if:
	./parse tests/test_if.c && touch tests/test_if.ll && cat test_llvm.ll > tests/test_if.ll

parse:grammar.c scanner.c expression_symbols.c hash.c
	$(CC) $(CFLAGS) -o $@ $^

grammar.c:grammar.y
	$(YACC) -t -d -o $@ --defines=grammar.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^

clean:
	rm -f grammar.c scanner.c parse grammar.tab.h *~
