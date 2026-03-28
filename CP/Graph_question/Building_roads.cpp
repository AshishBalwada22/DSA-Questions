// https://maang.in/problems/Building-Roads-192

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>visited;

void dfs(int cur){
    visited[cur]=1;
    for(auto nxt:edges[cur]){
        if(!visited[nxt]){
            dfs(nxt);
        }
    }
}
void solve(){

    int n,m;
    cin>>n>>m;
    edges.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}