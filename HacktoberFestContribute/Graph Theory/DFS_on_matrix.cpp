/*
    DFS on matrix to find the number of components of connected 1's
    e.g.
    11000
    11000
    00100
    00011
    
    ans: 3
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll m,n;
bool visited[1000][1000]={false};
int a[1000][1000]={0};

bool isSafe(int i, int j){
    if(i>=m || i<0 || j>=n || j<0){
        return false;
    }
    return true;
}

void dfs(int i, int j){    
    
    int xopt[]={0,0,-1,1};
    int yopt[]={1,-1,0,0};
    
    visited[i][j]=true;
    for(int p=0;p<4;p++){
        if(isSafe(i+xopt[p], j+yopt[p]) && !visited[i+xopt[p]][j+yopt[p]] && a[i+xopt[p]][j+yopt[p]] == 1){
            dfs(i+xopt[p], j+yopt[p]);
        }
    }
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    
    
    cin>>m>>n;
    
    vector<string> v;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int i=0;
    for(auto z:v){    
        for(int j=0;j<n;j++){
            a[i][j]=z[j]-'0';
        }
        i++;
    }
    
    int villages=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && a[i][j]==1){
                dfs(i, j);
                villages++;
            }
        }
    }
    
    cout<<villages<<endl;
    
    return 0;
}
