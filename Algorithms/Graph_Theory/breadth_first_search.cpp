#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int> > neighbours;
std::vector<int> distance;

void Init(int size)
{
 neighbours.resize(size+1);
 distance.resize(size+1);
 for(int i=0;i<=size;i++)
     distance[i]=-1;
}

void Add_neighbour(int x,int y)
{
 neighbours[x].push_back(y);
 neighbours[y].push_back(x);
}

void BFS(int starting_node)
{
 std::queue<int> _queue;
 _queue.push(starting_node);
 distance[starting_node]=0;
 while(!_queue.empty())
       {
        int q=_queue.front();
        for(int i=0;i<neighbours[q].size();i++)
            {
             int sqq=neighbours[q][i];
             if(distance[neighbours[q][i]]==-1)
                {
                 distance[neighbours[q][i]]=distance[q]+1;

                 int sq=distance[neighbours[q][i]];
                 _queue.push(neighbours[q][i]);
                }
            }
        _queue.pop();
       }
}


int main()
{
 FILE *in=fopen("a.in","r");
 int n,m;
 fscanf(in,"%d %d",&n,&m);
 Init(n);
 for(int i=0;i<m;i++)
     {
      int x,y;
      fscanf(in,"%d %d",&x,&y);
      Add_neighbour(x,y);
     }
 fclose(in);

 BFS(1);

 FILE *out=fopen("a.out","w");
 for(int i=1;i<=n;i++)
     {
      fprintf(out,"%d ",distance[i]);
     }
 fclose(out);
 return 0;
}
