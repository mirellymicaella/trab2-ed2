comp:
	clear
	gcc -o prog *.c

all: comp
	./prog ./input/entrada.txt ./output/saida.txt

test: item.c PQ.c list.c graph.c dijkstra.c
	clear
	gcc -o prog item.c PQ.c  list.c  graph.c dijkstra.c
	./prog 

cpp:
	clear
	g++ -o prog dijkstra.cpp
	./prog


#valgrind de teste
val: item.c PQ.c list.c dijkstra.c
	clear
	gcc -o prog item.c PQ.c list.c dijkstra.c
	valgrind --leak-check=full ./prog

#input 2
in2: comp
	./prog ./input/N100_S20_C30_M5.txt ./output/saida.txt