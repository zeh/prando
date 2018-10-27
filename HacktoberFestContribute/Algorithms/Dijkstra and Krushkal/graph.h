#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<limits.h>

using namespace std;

struct node{
	int data;
	int weight;
	//string label;
};

struct sd{
	int src,des;
	int wt;
};

class graph{
private:							//private members of the class graph
	node* **matrix;						//This is the adjacency matrix
        string *label;
        int **a;
        sd* *forest;
	sd* *sdmatrix;
        int n,edges;						//n->number of vertices, edges->number of edges
public:
        void buildGraph(int seed,int n,float t);		//member functions of the class graph that I have used for the required implementation
        void display();
        void initial(int size);
        sd** create_matrix();
        void krushkal();
	int min(int dist[], bool bool_Vertex[]);
        void dijkstra(int src);
        int Union(int src,int des);
        /*bool graph_empty();					//member functioons I didn't use
	void insert_vertex();
	bool insert_edge(int x,int y);
	bool give_label(int x,string d);
	void display_labels();
	bool adjacent(int x,int y);
	void delete_graph();
	bool find_label(string d);
        bool graph_full(string file);
        bool graph_complete();
        void status();
        void display_menu();
        int degree_vertex(int x);
        void neighbours_vertex(int x);
        void weight_edge(int x,int y,int w);
        void delete_edge(int x,int y);
        void delete_vertex(int x);*/
};

