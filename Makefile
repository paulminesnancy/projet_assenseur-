main.o: main.c
	gcc -c main.c

main: main.o
	gcc -c -o elevator main.o

run:
	./main

clean: 
	rm -g main *.o