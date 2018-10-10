#include <bits/stdc++.h>
using namespace std;
int nodes, edges, u, v, w;
vector< vector<pair<int,int> > >listt;
void add_edge(int u, int v, int w)
{
    listt[u].push_back({v,w});
}
int dijkstra(int source, int destination)
{
    vector<int>cost(nodes);
    for(int i=0; i<nodes ; i++)cost[i] = 1e9;
    set<pair<int,int> > st;
    cost[source] = 0;
    st.insert({0,source});
    while(st.size())
    {
        int current_node = st.begin()->second;
        int weight = st.begin()->first;
        st.erase(st.begin());
        if(current_node == destination )
            return weight;

        for(int i = 0 ; i < listt[current_node].size() ; i++)
        {
            int nxt = listt[current_node][i].first;
            int nxt_weight = listt[current_node][i].second;
            if(cost[nxt]> weight + nxt_weight)
            {
                cost[nxt] =  weight + nxt_weight;
                st.insert({cost[nxt],nxt});
            }
        }
    }
    return -1;
}
int main()
{
    cin>> nodes >> edges;
    listt.resize(nodes);
    for(int i=0; i<edges; i++)
    {
        cin>> u >> v >> w;
        add_edge(u, v, w);
    }
    cout<<dijkstra(0,nodes-1);
  return 0;
}
