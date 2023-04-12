kouros: main.o
cc main.o -o kouros

main.o: main.c
cc -c main.c

clean:
rm -f *.o kouros
