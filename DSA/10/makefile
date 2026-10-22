client.exe : client.o graph.o 
	gcc client.o graph.o -o client.exe 

client.o : client.c graph.h 
	gcc -Wall -Wextra -std=c99 -c client.c 

graph.o : graph.c graph.h
	gcc -Wall -Wextra -std=c99 -c graph.c 

clean:
	rm -f *.o client.exe