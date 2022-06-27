main.o: main.c
	gcc -c main.c

elevator.o: elevator.c
	gcc -c elevator.c 

person.o: person.c 
	gcc -c person.c

main: main.o
	gcc -c -o elevator main.o elevator.o person.o -lncurses

run:
	./main

clean: 
	rm -g main *.o