CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
LDLIBS = -lm

PROGRAMS = evaluatePostfix.exe infixToPostfix.exe

.PHONY: all clean

all: $(PROGRAMS)

evaluatePostfix.exe: evaluatePostfix.o stack.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

infixToPostfix.exe: infixToPostfix.o stack.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

evaluatePostfix.o: evaluatePostfix.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

infixToPostfix.o: infixToPostfix.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o $(PROGRAMS) 2>NUL || exit 0
