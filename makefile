comp:
	clear
	gcc -o prog *.c

all: comp
	./prog ./input/entrada.txt ./output/saida.txt

all10: comp
	./prog ./input/N10_S3_C3_M3.txt ./output/saida.txt

all100: comp
	./prog ./input/N100_S20_C30_M5.txt ./output/saida.txt

val10: comp
	valgrind --leak-check=full ./prog ./input/N10_S3_C3_M3.txt ./output/saida.txt

val100: comp
	valgrind --leak-check=full ./prog ./input/N100_S20_C30_M5.txt ./output/saida.txt

all1000: comp
	./prog ./input/N1000_S50_C300_M10.txt ./output/saida.txt

all10000: comp
	./prog ./input/N10000_S50_C300_M10.txt ./output/saida.txt

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