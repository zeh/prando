#include<stdio.h>
#include<conio.h>
#include<string.h>
//graphs implemented as adgency matrix
#define CONSTANT 1000
void createGraph(bool map[][CONSTANT],int edges)
{
	while(edges--)
	{
		int vertex1,vertex2;
		scanf("%d%d",&vertex1,&vertex2);
		map[vertex1][vertex2]=true;
		map[vertex2][vertex1]=true;
	}


}
void visitedNeighbours(bool map[][CONSTANT],int current,bool *visited,int vertices)
{
	printf("%d ",current);
	visited[current]=true;

	for(int i=1;i<=vertices;i++)
		if(map[current][i]&&!visited[i])
			visitedNeighbours(map,i,visited,vertices);

}
void DFS(bool map[][CONSTANT],int vertices)
{
	bool visited[CONSTANT];
	memset(visited,false,sizeof(visited));

	for(int i=1;i<=vertices;i++)
		if(!visited[i])
			visitedNeighbours(map,i,visited,vertices);



}


int main()
{
	bool map[1000][1000];
	memset(map,false,sizeof(map));
	int vertices=10;
	int edges=9;
	
	createGraph(map,edges);
	DFS(map,vertices);
	return 0;

}