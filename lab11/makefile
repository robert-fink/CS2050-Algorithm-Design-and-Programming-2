lab11: frontend.o parcer.o
	gcc frontend.o parcer.o -g -Wall -o lab11

frontend.o: frontend.c parcer.h
	gcc -c frontend.c

parcer.o: parcer.c parcer.h
	gcc -c parcer.c

clean:
	rm *o lab11
