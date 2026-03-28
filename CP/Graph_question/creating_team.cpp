// https://maang.in/problems/Creating-Teams-193

#include<bits/stdc++.h>
using namespace std;

bool bipartite=true;

vector<int>color;
void dfs(int cur,int col,vector<vector<int>>&edges,vector<int>&visited){
    visited[cur]=1;
    color[cur]=col;
    for(auto nxt:edges[cur]){
        if(!visited[nxt]){
            dfs(nxt,3-col,edges,visited);
        }else if(color[nxt]==col){
            bipartite=false;
            return;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    color.resize(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,1,edges,visited);
        }
    }
    if(bipartite) cout<<"YES";
    else cout<<"NO";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}