#include <bits/stdc++.h> 
using namespace std; 
#define MAXN 100000 
#define level 18 
  
vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN][level]; 
  
// pre-compute the depth for each node and their 
// first parent(2^0th parent) 
// time complexity : O(n) 
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs(tree[cur][i], cur); 
    } 
} 
  
// Dynamic Programming Sparse Matrix Approach 
// populating 2^i parent for each node 
// Time complexity : O(nlogn) 
void precomputeSparseMatrix(int n) 
{ 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 
  
// Returning the LCA of u and v 
// Time complexity : O(log n) 
int lca(int u, int v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    int diff = depth[v] - depth[u]; 
  
    // Step 1 of the pseudocode 
    for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
  
    // now depth[u] == depth[v] 
    if (u == v) 
        return u; 
  
    // Step 2 of the pseudocode 
    for (int i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
} 
  
  
// driver function 
int main() 
{ 
    
    memset(parent,-1,sizeof(parent)); 
    cout<<"Enter the number of nodes"<<endl;
    int nodes;
    cin>>nodes;
    cout<<"Enter the edge details"<<endl;
    for(int i = 1;i<nodes;i++){
        int node1,node2;
        cin>>node1>>node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    depth[0] = 0; 
  
    // running dfs and precalculating depth 
    // of each node. 
    dfs(1,0); 
  
    // Precomputing the 2^i th ancestor for evey node 
    // precomputeSparseMatrix(nodes); 
  
    int x,y;
    cout<<"Enter the two nodes you want to find lca"<<endl;
    cin>>x>>y;
    cout<<x<<" "<<y<<endl;
    cout<<"LCA of "<<x<<" and "<<y<<" = "<<lca(x,y);
    return 0; 
} 