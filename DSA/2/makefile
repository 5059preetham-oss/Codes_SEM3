all: client.exe client_rect.exe

client.exe : client.o list.o rect.o
	gcc client.o list.o rect.o -o client.exe

client.o : client.c list.h rect.h
	gcc -Wall -Wextra -pedantic -c client.c

list.o : list.c list.h rect.h
	gcc -Wall -Wextra -pedantic -c list.c

rect.o : rect.c rect.h
	gcc -Wall -Wextra -pedantic -c rect.c

client_rect.exe : client_rect.o rect.o
	gcc client_rect.o rect.o -o client_rect.exe

client_rect.o : client_rect.c rect.h
	gcc -Wall -Wextra -pedantic -c client_rect.c

clean:
	del /Q *.o client.exe client_rect.exe 2>NUL

.PHONY: all clean

