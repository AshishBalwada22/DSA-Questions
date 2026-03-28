// https://maang.in/problems/Round-Trip-194

#include<bits/stdc++.h>
using namespace std;

// detect cycle in undirected graph
bool dfs(int cur,int parent, vector<vector<int>>&edges, vector<int>&visited){
    visited[cur]=1;
    for(auto nxt:edges[cur]){
        if(!visited[nxt]){
            bool ans = dfs(nxt,cur,edges,visited);
            if(ans) return true;
        }else if(parent!=nxt){
            return true;
        }
    }
    return false;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int>visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool ans = dfs(i,-1,edges,visited);
            if(ans){
                cout<<"YES";
                return;
            }
        }
    }
    cout<<"NO";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}