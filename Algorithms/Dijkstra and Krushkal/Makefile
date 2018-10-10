CFLAGS = -D DEBUG

all:graph

graph:func.o graph.o
	g++ -o graph func.o graph.o

func.o:graph.h func.cpp
	g++ -c $(CFLAGS) graph.h func.cpp

graph.o:graph.cpp
	g++ -c $(CFLAGS) graph.cpp -o graph.o

clean:
	rm -f *.o graph
