hw3: frontend.o analysis.o
	gcc frontend.o analysis.o -g -Wall -o hw3

frontend.o: frontend.c analysis.h
	gcc -c frontend.c

analysis.o: analysis.c analysis.h
	gcc -c analysis.c

clean:
	rm *o hw3
