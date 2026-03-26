// https://maang.in/problems/Colour-Tree-416

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;

void solve(){
    int n;
    cin>>n;
    edges.resize(n+1);
    vector<int>indegree(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }
    // color of my neighbours and myself should be distinct - that will be the answer
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,indegree[i]);
    }
    cout<<ans+1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}