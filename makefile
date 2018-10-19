all: main.o linkedlist.o library.o
	gcc main.o linkedlist.o library.o

main.o: main.c linkedlist.h library.h
	gcc -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

library.o: library.c library.h
	gcc -c library.c
    
run:
	./a.out

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf *.out
