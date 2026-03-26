// https://maang.in/problems/Easy-Graph-Queries-400


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<ll>>edges;
vector<ll>visited;
vector<ll>comp; // node lie in which component

void dfs(ll cur,ll comp_no){
    visited[cur]=1;
    comp[cur]=comp_no;
    for(auto nxt:edges[cur]){
        if(!visited[nxt]){
            dfs(nxt,comp_no);
        }
    }
}

void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    edges.resize(n+1);
    visited = vector<ll>(n+1,0);
    comp = vector<ll>(n+1,-1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ll comp_no=0;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            comp_no++;
            dfs(i,comp_no);
        }
    }
    vector<ll>comp_size(comp_no+1,0);
    for(ll i=1;i<=n;i++){
        comp_size[comp[i]]++;
    }
    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll x;
            cin>>x;
            cout<<comp_size[comp[x]]<<endl;
        }else if(type==2){
            ll x,y;
            cin>>x>>y;
            if(comp[x]==comp[y]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}