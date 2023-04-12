kouros: main.o storage.o
	cc main.o storage.o -o kouros

main.o: main.c
	cc -c main.c

storage.o: storage.c
	cc -c storage.c

clean:
	rm -f *.o kouros
