// https://maang.in/problems/Round-Trip-II-388

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(n+1);
    // khan's algorithm
    vector<int>indegree(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    int element=0;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        element++;
        for(auto nxt:edges[cur]){
            indegree[nxt]--;
            if(indegree[nxt]==0){
                q.push(nxt);
            }
        }
    }
    // if there is a cycle in directed graph, then there is no element in the DAG whose indegree is 0, and i can't traverse whole element
    if(element != n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}