#include<iostream>
#include<stdlib.h>
#include"graph.h"
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(int argc,char* argv[]){
	int n,i=0,j=0;
	int seed=atoi(argv[1]);		//taking seed as argument
	n=atoi(argv[2]);		//number of vertices
	float t=atof(argv[3]);		//threshold value
	//string file="input1.txt";
	graph g;
	g.initial(n);
	g.buildGraph(seed,n,t);		//builds the graph
	g.display();			//displays the adjacency graph
	g.krushkal();			//function for krushkal's algorithm
	int vertex;
	cout<<"enter the vertex(from 1 to "<<n<<")"<<endl;
	cin>>vertex;			//vertex for input for dijkstra
	g.dijkstra(vertex-1);		//function for dijkstra's algorithm
	return 0;
}
