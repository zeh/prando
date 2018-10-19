#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// global variable that will keep track of depth if input node is found. 
int depth=-1;
// 
ll sum_of_siblings=0;
// this dfs is to find the depth of the node  and get sum of sibling so that the siblings sum value will be used to subtract from the total value at particular depth.
// root depth is zero 
// 
void dfs_for_finding_node(int rt,int to_fnd,int depth_t,vector< vector<int>> &tree,vector<ll> &val,int p=-1){
	      ll sum=0;
        bool add=false;
        for(int e : tree[rt] ) { 
                  if(e== p ) continue;
                  sum+=val[e];
              if(e==to_fnd){
                          add=true;
          }
        }	
        
        for(int e : tree[rt] ) {
            if(e==p) continue;
            dfs_for_finding_node(e,to_fnd,depth_t+1,tree,val,rt);
	      }	
        if(add) {
            sum_of_siblings=sum;
            depth=depth_t+1;
        }
}
ll global_sum_at_level=0;
// this dfs is to find the sum at specific depth.
void dfs2(int rt,int depth_t,vector< vector<int>> &tree,vector<ll> &val,int p=-1){

    if(depth_t == depth) {global_sum_at_level+=val[rt]; return;} 
    for(int e : tree[rt] ) { 
              if(e== p ) continue;
              dfs2(e,depth_t+1,tree,val,rt);
    }	
}

int main(){
	      int n,root,node;
        // n = total number of node.
        // I have assumed the node labet to be 1 indexed.
        // root= root node-index.
        // node= index of node of which we want to find the cousins sum.
        // values taken in long long int
        //assumed that answer will fit in long long int
        cin >> n>>root >> node;
        vector<ll> values(n+1);
        for(int i=0;i<n;i++) cin >> values[i+1];
        vector< vector<int> > tree(n+1);
              // taking input of edges of tree.
              // u and v means there is an edge from u to v .(undirected edge)
        for(int i=1;i<=n-1;i++)  {
          int u,v; cin >> u >>v;
          tree[u].push_back(v); tree[v].push_back(u);   
        }
        if(node==root) {
                  cout << 0 << endl;
              }
              else{
                  dfs_for_finding_node(root,node,0,tree,values);
                  if(depth == -1) {
                      cout << 0 << endl;
                  }
                  else{
                      //cout << depth << endl;
                      dfs2(root,0,tree,values);
                      cout << global_sum_at_level-sum_of_siblings << endl;
                  }
              }
        return 0;
}
