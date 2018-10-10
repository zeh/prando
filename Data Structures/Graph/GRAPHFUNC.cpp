#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include"GRAPH.h"

using namespace std;

bool graph::graph_full(string file){			//Function to check if any vertices could be added to the graph or not
	int temp,total=0;
	ifstream f;
	f.open(file.c_str());
	while(f>>temp){
		total++;
	}
	//cout<<total<<" ";
	total=sqrt(total);
	//cout<<total<<endl;
	if(total==n){cout<<"Graph is full"<<endl;return true;}
	else if(n<total){cout<<"Graph is not full"<<endl;return false;}
	//else{cout<<"Doesn't Exist"<<endl;return false;}
}

void graph::display_menu(){				//Menu for the user to make a choice of what he wants to know
	cout<<"1. Number of vertices\n";
	cout<<"2. Degree of vertex\n";
	cout<<"3. Neighbours of a given vertex\n";
	cout<<"4. Number of edges\n";
}

void graph::neighbours_vertex(int x){			//function to dispaly the neighbours of a particular vertex
	if(x<=n && x>0){
		cout<<"Neighbours of vertex "<<x<<" are ";
		for(int i=0;i<n;i++){			//displays the neighbours if such a vertex exists
			if(matrix[x-1][i]->data!=0){cout<<i+1<<" ";}
		}
		cout<<endl;
	}
	else{						//Else displays an error message
		cout<<"No such vertex exists"<<endl;
	}
}

void graph::weight_edge(int x,int y,int w){		//Displays the weight of a particular edge
	if(x<=n && y<=n && x>0 && y>0){
		matrix[x-1][y-1]->weight=w;
		matrix[y-1][x-1]->weight=w;
	}
	else{
		cout<<"No such pair of vertices exist"<<endl;
	}
}

void graph::delete_edge(int x,int y){			//deletes a particular edge from the given undirected graph
	if(x<=n && y<=n && x>0 && y>0){
		matrix[x-1][y-1]->data=0;
		matrix[y-1][x-1]->data=0;
		edges--;
	}
	else{						//if no such pair of edges exist then displays the error message 
		cout<<"No such pair of vertices exist"<<endl;
	}
}

void graph::delete_vertex(int x){			//deletes a particular vertex from the given graph		
	if(x<=n && x>0){				//checks if the vertex is present or not
		node* **b;
		int degree=degree_vertex(x);				
		b=new node**[n-1];
		for(int i=0;i<n-1;i++){
			b[i]=new node*[n-1];
		}
		int k=0,l=0;
		for(int i=0;i<n;i++){			//if present deletes the vertex by creating a new adjacency matrix
			l=0;				//and coping all the elements other than the elements beloning to this vertex 
			if(i!=x-1){
				for(int j=0;j<n;j++){
					if(j!=x-1){
						b[k][l]=matrix[i][j];
						l++;
					}
				}
			k++;
			}
		}
		matrix=new node**[n-1];
		for(int i=0;i<n-1;i++){
                	matrix[i]=new node*[n-1];
        	}
        	matrix=b;
        	string *newlabel = new string[n-1];
        	l=0;
        	for(int i=0;i<n;i++){			//again rearranges the labels of the vertices accordingly
        		if(i!=x-1){
        			newlabel[l]=label[i];
        			l++;
        		}
        	}
        	label=newlabel;
        	n--;					//updating 
        	edges=edges-degree;			//updating the number of edges after deleting the vertex
	}
	else{						//prints the error message if no such vertex exists
		cout<<"No such vertex exists"<<endl;
	}
}

int graph::degree_vertex(int x){			//function to find the degree of a undirected graph
	int degree=0;
	if(x<=n && x>0){				//if vertex is present then prints the degree of the vertex
		for(int i=0;i<n;i++){
			if(i!=x-1){			//if both the end vertices of the edge then it forms a loop
				degree+=matrix[x-1][i]->data;	//then one to the exixting degree
			}
			else{				//if both the end vertices of the edge then it forms a loop
				degree+=matrix[x-1][i]->data*2;	//it contributes twice than the normal edge
			}
		}
		cout<<"Degree of vertex "<<x<<" is "<<degree<<endl;
		return degree;
	}
	else{						//if vertex is not present prints the appropriate error message
		cout<<"No such vertex exists"<<endl;
		return -1;				//to check that no such vertex is present as degree of no vertex can be negative
	}
}

void graph::status(){					//Prints the required status of the graph according to the user input
	int option;
	char choice='y';
	while(choice=='y' || choice=='Y'){
		display_menu();
		cout<<"select an option "<<endl;
		cin>>option;
		if(option==1){				//if the input is one then displays the number of vertices
			cout<<"Number of vertices are "<<n<<endl;
		}
		else if(option==2){			//if option is two then prints the degree of the vertex in the undirected graph
			cout<<"Enter the vertex\n";
			int x;
			cin>>x;
			degree_vertex(x);
		}
		else if(option==3){			//if option is 3 then prints the neighbours of the vertex
			cout<<"Enter the vertex\n";
			int x;
			cin>>x;
			neighbours_vertex(x);
		}
		else if(option==4){			//if option is 4 then prints the number of edges
			cout<<"Number of edges are "<<edges<<endl;
		}
		else{
			cout<<"No such option exists\n";
		}
		cout<<"Do you want to find another status[y/n]\n";
		cin>>choice;
	}
}

bool graph::find_label(string d){			//finds the vertex with a given label
	for(int i=0;i<n;i++){
		if(label[i]==d){
			cout<<"label found at index "<<i<<endl;
			return true;
		}
	}
	return false;
}

void graph::delete_graph(){				//deletes the whole graph
	for(int i=0;i<n;i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] label;
	cout<<"deleted"<<endl;
}

bool graph::adjacent(int x,int y){			//finds if the given two vertices are adjacent or not
	if(x<=n && y<=n && x>0 && y>0){
		if(matrix[x-1][y-1]->data!=0){cout<<"adjacent"<<endl;return true;}
		else{cout<<"not adjacent"<<endl;return false;}
	}
	else{
		cout<<"No such pair of vertices exists"<<endl;
		return false;
	}
}

void graph::initial(int size){				//initialises the matrix of labels of the graph
        n=size;
        label=new string[n];
        for(int i=0;i<n;i++){
        	label[i]="";
        }
}

void graph::buildGraph(int n,string file){			//Builds the graph by taking the input from the file
        edges=0;
        int temp,i=0,j=0;
	node* elem;
        matrix=new node**[n];					//creating  a matrix
        for(i=0;i<n;i++){
                matrix[i]=new node*[n];
        }
	i=0;
	ifstream f;
	f.open(file.c_str());
	while(i<n){						//i represents number of rows				
		j=0;
		while(j<n){					//reads the required number of elements of a particular row
			elem=new node;
			f>>temp;				//reading the input from the file
			elem->data=temp;
			elem->weight=1;
			matrix[i][j]=elem;			//inserts the elements into the adjacency matrix by reading from the file
			edges=edges+temp;
			j++;
		}
		char c;
		while(f.get(c)){				//ignores the remaining elements of the row
			if(c=='\n'){
				break;
			}
		}
		i++;
	}
	edges=edges/2;						//updating the number of edges
}

void graph::display(){					//function to display the adjacency matrix
        int i,j;
        for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<matrix[i][j]->data<<" ";
		}
		cout<<endl;
	}
}

bool graph::graph_empty(){				//function to check if the graph is empty or not
        if(n==0){return true;}
        return false;
}

bool graph::graph_complete(){				//function to check if the given graph is complete or not
        int max=n*(n-1);
        max=max/2;
        if(max==edges){return true;}
        return false;
}

void graph::insert_vertex(){				//function to add the vertex to the given graph
	n++;
	node* **b;
	b=new node**[n];
	node* elem;
        for(int i=0;i<n;i++){
                b[i]=new node*[n];
        }
	for(int i=0;i<n;i++){				
		for(int j=0;j<n;j++){			
			elem=new node;
			if(i==n-1){			//and adding the new vertex in the last row of adjacency matrix
				elem->data=0;
				elem->weight=1;
				b[i][j]=elem;
			}
			else if(j==n-1){		//and adding the new vertex in the last column of adjacency matrix
				elem->data=0;
				elem->weight=1;
				b[i][j]=elem;
			}
			else{				//coping all the elements from the previous adjacency matrix
				b[i][j]=matrix[i][j];
			}
		}
	}
	matrix=new node**[n];				//deleting the previous matrix
        for(int i=0;i<n;i++){
                matrix[i]=new node*[n];
        }
        string *newlabel;
        newlabel=new string[n];
        for(int i=0;i<n;i++){				//creating a new label array for maintaining the labels of vertices
        	if(i==n-1){
        		newlabel[i]="";
        	}
        	else{
        		newlabel[i]=label[i];
        	}
        }
        label=new string[n];				//passing the address of the new label matrix and new adjacency matrix to the 
        label=newlabel;					//old label and adjacency matrix
	matrix=b;
}

bool graph::insert_edge(int x,int y){			//function to add an edge between given two vertices for an undirected graph
	if(x<=n && y<=n && x>0 && y>0){
		matrix[x-1][y-1]->data+=1;
		matrix[y-1][x-1]->data+=1;
		edges=edges+1;
		return true;
	}
	return false;
}

bool graph::give_label(int x,string d){			//function to designate to label to given vertex
	if(x<=n && x>0){
		label[x-1]=d;
		return true;
	}
	return false;
}

void graph::display_labels(){				//function to display the labels of every vertex
	for(int i=0;i<n;i++){
		cout<<label[i]<<endl;
	}
}
