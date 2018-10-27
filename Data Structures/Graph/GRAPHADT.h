#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

struct node{						//structure of the element of the adjacency matrix
	int data;
	int weight;
};

class graph{
private:						//private members of the class graph
	node* **matrix;					//This is the adjacency matrix
        string *label;					//for storing the labels of the vertices
        int **a;
        int n,edges;					//n->number of vertices, edges->number of edges
public:
        void buildGraph(int n,string file);		//member functions of the class graph 
        void display();
        void initial(int size);
        bool graph_empty();
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
        void delete_vertex(int x);
};

