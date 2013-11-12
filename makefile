main: queue.o main.o graph.o
	gcc -o main queue.o main.o graph.o

graph.o: graph.c graph.h queue.h
	gcc -c graph.c

queue.o: queue.c queue.h
	gcc -c queue.c

main.o: main.c queue.h
	gcc -c main.c

clean:
	rm -rf *.o
