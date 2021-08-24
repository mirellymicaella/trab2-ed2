comp:
	clear
	gcc -o prog *.c

all: comp
	./prog ./input/entrada.txt ./output/saida.txt

test: item.c PQ.c list.c dijkstra.c
	clear
	gcc -o prog item.c PQ.c list.c dijkstra.c
	./prog 

val: item.c PQ.c list.c dijkstra.c
	clear
	gcc -o prog item.c PQ.c list.c dijkstra.c
	valgrind --leak-check=full ./prog

in2: comp
	./prog ./input/N100_S20_C30_M5.txt ./output/saida.txt