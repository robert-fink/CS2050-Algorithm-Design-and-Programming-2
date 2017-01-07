lab8: potato.o queue.o
	gcc potato.o queue.o -Wall -g -o lab8

potato.o: potato.c queue.h
	gcc -c potato.c

queue.o: queue.c queue.h
	gcc -c queue.c

clean:
	rm *o lab8
