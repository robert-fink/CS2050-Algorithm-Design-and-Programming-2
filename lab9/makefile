lab9: runner.o bst.o
	gcc runner.o bst.o -Wall -o lab9

runner.o: runner.c bst.h
	gcc -c runner.c

bst.o: bst.c bst.h
	gcc -c bst.c

clean:
	rm *o lab9

