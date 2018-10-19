//Floyd-Warshall Algorithm: all pair shortest path
#include <iostream>
#include <climits>
using namespace std;

#define INF 999999999

int main()
{
	int graph[1001][1001],i,j,k,n,m;
	cin>>n>>m;	//number of vertices and edges respectively

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(i==j)	graph[i][j]=0;	//Shortest distance between (i,i) is 0
			else
				graph[i][j] = INF;		//Initializing other distances as infinite
	}

	for(i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u][v] = w;				//input graph
		graph[v][u] = w;				//Shortest distance between (i,j) using atmost one edge
	}


	for(k=1;k<=n;k++)					
	{
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				//Shortest distance between (i,j) using atmost k edges
				graph[u][v] = min(graph[u][v],graph[u][k]+graph[k][v]);	
			}
		}
	}

	//Resulting all pair shortest path in given graph
	for(int u=1;u<=n;u++)
	{
		for(int v=1;v<=n;v++)
		{
			cout<<graph[u][v]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}

/*
Input:-
First line contain two space separated integer n and m 
where n is the number of vertices and m is the number 
of edges.Next m lines contains three space seprated integers
u, v and w which represents that there is an edge between u and v
and weight of the edge is w

Sample Input:-
6 9
1 2 1
1 3 2
1 4 5
2 4 5
2 5 2
3 4 3
4 5 1
4 6 1
5 6 4
*/
