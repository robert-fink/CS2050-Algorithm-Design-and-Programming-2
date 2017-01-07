hw3: frontend.o calculator.o stack.o
	gcc frontend.o calculator.o stack.o -g -Wall -o hw3

frontend.o: frontend.c calculator.h stack.h
	gcc -c frontend.c

calculator.o: calculator.c calculator.h stack.h
	gcc -c calculator.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *o hw3
