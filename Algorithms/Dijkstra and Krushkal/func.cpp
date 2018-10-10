#include"graph.h"

using namespace std;

int graph :: min(int dist[],bool bool_Vertex[])
{
   	int min = INT_MAX, min_index;				//initialise the min value with the largest integer
	for (int v = 0; v < n; v++)				//to find the minimum distance 
   	{
     		if (bool_Vertex[v] == false && dist[v]<=min){
         		min = dist[v];
         		min_index = v;
         	}
   	}
   	return min_index;					//return the index of minimum distance
}

void graph :: dijkstra(int src)					//function to find shortest path from the source to any other vertex
{
	if(src<n){
	     	int dist[n];
	     	bool bool_Vertex[n];
	     	for (int i = 0; i < n; i++){
			dist[i] = INT_MAX, bool_Vertex[i] = false;
		}
	     	dist[src]=0; 						//making distance from source to source equal to zero
	     	for (int count = 0; count < n-1; count++){
	       		int u = min(dist, bool_Vertex);
	       		bool_Vertex[u] = true;
	       		for (int v = 0; v < n; v++)
			{
		 		if (!bool_Vertex[v] && matrix[u][v]->data && dist[u] != INT_MAX && dist[u]+matrix[u][v]->weight < dist[v]){
		    			dist[v] = dist[u] + matrix[u][v]->weight;	//updating the shortest distance 
		    			//cout<<u+1<<" "<<v+1<<endl;
		    		}
			}    
	     	}
	     	cout<<"Dijkstra's shortest path :"<<endl;
	     	cout<<"Distance from Source "<<src+1<<" to "<<endl;
	   	for (int i = 0; i < n; i++){				//printing the shortest distances from source to all other vertices
	      		cout<<i+1<<" is "<<dist[i]<<endl;
	      	}
	}
	else{
		cout<<"No such vertex exists"<<endl;
	}
}

sd** graph::create_matrix(){					//function to create an array of edges in the increasing order of their
	sdmatrix=new sd*[edges];				//weight
        int k=0;
        for(int i=0;i<n;i++){					//first creating an array consisting of the information of source
        	for(int j=i;j<n;j++){				//destination and weight of the edge
        		if(matrix[i][j]->data!=0 && k<edges){
        			sd* temp=new sd;
        			temp->src=i+1;
        			temp->des=j+1;
        			temp->wt=matrix[i][j]->weight;
				sdmatrix[k]=temp;
				k++;
        		}
        	}
        }
        for(int i=0;i<edges;i++){				//sorting the above array on the basis of weight in non-decreasing order
        	sd* temp=new sd;
        	temp=sdmatrix[i];
        	int j=i;
        	while(j>0 && sdmatrix[j-1]->wt>temp->wt){
        		sdmatrix[j]=sdmatrix[j-1];
        		j--;
        	}
        	sdmatrix[j]=temp;
        }
        /*for(int i=0;i<edges;i++){
        	cout<<sdmatrix[i]->src<<" "<<sdmatrix[i]->des<<" "<<sdmatrix[i]->wt<<endl;
        }*/
        return sdmatrix;     
}

int graph::Union(int src,int des){
	int flag=0;		//initially  make the flag to zero
	for(int j=0;forest[j]!=NULL&&j<n-1;j++){		//loop to check if the adding edge forms a cycle 
		if(src==forest[j]->src||src==forest[j]->des){	//with the existing forest or not
			for(int k=0;forest[k]!=NULL&&k<n-1;k++){
				if(des==forest[k]->src||des==forest[k]->des){	//if it forms a cycle then 
					flag=1;					//flag is made to 1 representing 
					break;					//cycle is formed
				}
			}
			if(flag==1){	//comes out of the loop if cycle is formed
				break;
			}
		}
	}
	return flag;
}

void graph::krushkal(){				//Function to implement krushkals algorithm to find the minimum spanning tree
	create_matrix();
	cout<<endl;
	forest=new sd*[n-1];			//Create a forest consisting of all the vertices and zero adges
	for(int i=0;i<n-1;i++){			
		forest[i]=NULL;
	}
	int c=0;				//count to check how many edges have been added
	int flag=0;				//flag to check if the edge adding forms a cycle or not
	for(int i=0;i<edges;i++){		//Running the loop for total edges
		sd* temp=new sd;
		temp=sdmatrix[i];
		int src=temp->src;
		int des=temp->des;
		if(src!=des){
			if(c<n-1){	//check if the spanning tree is formed or not
				if(forest[0]==NULL){	//adding the edge with minimum weight to the forest initially 
					forest[0]=temp;
					c++;
				}
				else{					//if the forest is not empty(i.e., having some edges)
					flag=Union(src,des);		//Function to find if the edge forms the cycle or not
					if(flag==0){			//add the edge to the foreest if the cycle is not formed
						for(int j=0;j<n-1;j++){
							if(forest[j]==NULL){
								forest[j]=temp;
								c++;
								break;
							}
						}
					}
				}					//if the cycle is formed don't add the edge and move the iteration to 
			}						//next edge
			else{						//if n-1 edges have been added to the forest means if the minimum spanning
				break;					//tree is formed the break from the loop
			}
		}
	}
	//cout<<"ok"<<" "<<c<<endl;
	if(c==n-1){
		cout<<"Graph according to the krushkal's algorithm: "<<endl;
		cout<<"source"<<"		"<<"destination"<<"	"<<"weight"<<endl;
		for(int i=0;i<n-1;i++){
			cout<<forest[i]->src<<"		"<<forest[i]->des<<"		"<<forest[i]->wt<<endl;
		}
	}
	else{
		cout<<"It is a disconnected graph. Krushkal's algorithm can't be applied"<<endl;
	}
}

void graph::initial(int size){				//initialises the matrix of labels of the graph
        n=size;
        label=new string[n];
        for(int i=0;i<n;i++){
        	label[i]="";
        }
}

void graph::buildGraph(int seed,int n,float t){			//Builds the graph by taking input randomly
        edges=0;
        int temp,i=0,j=0;
		node* elem;
        matrix=new node**[n];
        for(i=0;i<n;i++){
                matrix[i]=new node*[n];
        }
		i=0;
		srand(seed);
		for(i=0;i<n;i++){				//creating an adjacency matrix
			for(int j=i;j<n;j++){
				elem=new node;
				int r=rand()%500;		//rand function to generate a number randomly
				float p=((float)r)/500;
				//cout<<i+1<<" "<<j+1<<" "<<r<<" "<<p<<" "<<t<<" ";
				int weight;
				if(p<t){			//if p less than the threshold value t then edge is present with the required weight
					weight=p*100;
					elem->data=1;
					elem->weight=weight;
					edges=edges+1;
					//cout<<weight<<endl;
				}
				else{				//otherwise edge is not present
					elem->data=0;
					elem->weight=0;
					//cout<<0<<endl;
				}
				matrix[i][j]=elem;
				matrix[j][i]=elem;
			}
		}
	//cout<<edges<<endl;
}

void graph::display(){					//function to dispaly the adjacency matrix of the given graph
        int i,j;
        cout<<"Adjacency Matrix is :"<<endl;
        for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<matrix[i][j]->data<<" ";
		}
		cout<<endl;
	}
}

/*
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
			l=0;
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
        	n--;
        	edges=edges-degree;
	}
	else{						//prints the error message if no such vertex exists
		cout<<"No such vertex exists"<<endl;
	}
}

int graph::degree_vertex(int x){			//function to find the degree of a undirected graph
	int degree=0;
	if(x<=n && x>0){				//if vertex is present then prints the degree of the vertex
		for(int i=0;i<n;i++){
			if(i!=x-1){
				degree+=matrix[x-1][i]->data;
			}
			else{
				degree+=matrix[x-1][i]->data*2;
			}
		}
		cout<<"Degree of vertex "<<x<<" is "<<degree<<endl;
		return degree;
	}
	else{						//if vertex is not present prints the appropriate error message
		cout<<"No such vertex exists"<<endl;
		return -1;
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


bool graph::graph_empty(){
        if(n==0){return true;}
        return false;
}

bool graph::graph_complete(){
        int max=n*(n-1);
        max=max/2;
        if(max==edges){return true;}
        return false;
}

void graph::insert_vertex(){
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
			if(i==n-1){
				elem->data=0;
				elem->weight=1;
				b[i][j]=elem;
			}
			else if(j==n-1){
				elem->data=0;
				elem->weight=1;
				b[i][j]=elem;
			}
			else{
				b[i][j]=matrix[i][j];
			}
		}
	}
	matrix=new node**[n];
        for(int i=0;i<n;i++){
                matrix[i]=new node*[n];
        }
        string *newlabel;
        newlabel=new string[n];
        for(int i=0;i<n;i++){
        	if(i==n-1){
        		newlabel[i]="";
        	}
        	else{
        		newlabel[i]=label[i];
        	}
        }
        label=new string[n];
        label=newlabel;
	matrix=b;
}

bool graph::insert_edge(int x,int y){
	if(x<=n && y<=n && x>0 && y>0){
		matrix[x-1][y-1]->data+=1;
		matrix[y-1][x-1]->data+=1;
		edges=edges+1;
		return true;
	}
	return false;
}

bool graph::give_label(int x,string d){
	if(x<=n && x>0){
		label[x-1]=d;
		return true;
	}
	return false;
}

void graph::display_labels(){
	for(int i=0;i<n;i++){
		cout<<label[i]<<endl;
	}
}

*/
