//DFS SEARCH 
#include<bits/stdc++.h>
using namespace std;
//GRAPH IMPLEMENTED AS ADJACENCY LIST

 void createGraph(vector<vector<int> >&graph,int edges)
 {
    while(edges--)
    {
        int vertex1,vertex2;
        cin>>vertex1>>vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

}
void visitNeighbours(vector<vector<int> >&map,int current,bool *visited)
{   cout<<current<<" ";

    visited[current]=true;
    for(int i=0;i<map[current].size();i++)
    if(!visited[map[current][i]])
        visitNeighbours(map,map[current][i],visited);
    
}

void DFS(vector<vector<int> >&map,int vertices)
{
    bool *visited=new bool[vertices+1];

    for(int i=1;i<=vertices;i++)
    if(!visited[i])
           
            visitNeighbours(map,i,visited);
        

    




}


int main()
{
     vector<vector<int> >graph;
     int vertices=10;
     int edges=9;
     graph.resize(vertices+1);

     
     

     createGraph(graph,edges);
     DFS(graph,vertices);
     return 0;

}
/* EXPLANATION
  
   graph=>

    1----2---5---6       8-9
     \       |\   
      \      | \ 
       3-----4  7 


   the graph contains two connected components


   expexted input=>
     1-2
     1-3
     2-5
     3-4
     4-5 
     5-6
     5-7
     8-9
     9-10

     first we would visit the vertex that is unvisited the visited nodes would be marked visited int visited[] array
     once we jump to that unvisited node we would further jump to it's next corresponding neighbour
     and that would become our current unvisited node so first we would visited the neighbours of our smaller neighbour
     and then jump to larger

     
     representation of graph in vector form
    (*)
     1---2----3                                     output==> 1
      
     2---1----5
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
     
     7---6

     8---9

     9---8


        
     
        (*)
     1---2----3                                    output==>1 2
      
     2---1----5
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
     
     7---6
     
     8---9

     9---8




     1---2----3
    (*) 
     2---1----5
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
     
     7---6

     8---9

     9---8




     1---2----3
             (*)     
     2---1----5                        output==>1 2 5
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
     
     7---6

     8---9

     9---8




     1---2----3
      
     2---1----5
     
     3---1----4
     
     4---3----5
    (*)
     5---2----4----6----7
     
     6---5
     
     7---6

     8---9

     9---8


    
     1---2----3
      
     2---1----5
     
     3---1----4                        output==>1 2 5 4
     
     4---3----5
             (*)  
     5---2----4----6----7
     
     6---5
     
     7---6

     8---9

     9---8




     1---2----3
      
     2---1----5                        output==>1 2 5 4 6
     
     3---1----4
    
     4---3----5
     
     5---2----4----6----7
    (*)
     6---5
     
     7---6

     8---9

     9---8


     
     1---2----3
      
     2---1----5                       output==>1 2 5 4 6 7 
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
    (*)
     7---6

     8---9

     9---8

        
     

     1---2----3
      
     2---1----5                       output==>1 2 5 4 6 7 8 
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
    
     7---6
    (*)
     8---9

     9---8


   
     1---2----3
      
     2---1----5                       output==>1 2 5 4 6 7 8 9 
     
     3---1----4
     
     4---3----5
     
     5---2----4----6----7
     
     6---5
    
     7---6

     8---9
    (*)
     9---8
*/