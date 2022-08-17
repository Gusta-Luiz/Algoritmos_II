# Finally we need to tell "make" what source and header file each object file depends on
AlgoritmosII: main.o inicializa.o #algoritmos2.o
	gcc -o AlgoritmosII main.o inicializa.o #algoritmos2.o

inicializa.o: inicializa.c inicializa.h
	gcc -c inicializa.c

#algoritmos2.o: algoritmos2.c algoritmos2.h
#	gcc -c algoritmos2.c

main.o: main.c inicializa.c inicializa.h #algoritmos2.c algoritmos2.h
	gcc -c main.c

# Target to clean up after us
clean:
	-rm -f AlgoritmosII 
	-rm -f *.o 