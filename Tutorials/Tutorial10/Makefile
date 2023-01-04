myExec: main.o person.o mystat.o
	gcc -o myExec main.o person.o mystat.o

person.o : person.h person.c mystat.h
	gcc -c person.c

main.o : main.c person.h
	gcc -c main.c

mystat.o : mystat.c mystat.h
	gcc -c mystat.c

clean : 
	rm -f *.o
