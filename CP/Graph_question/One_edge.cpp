// https://maang.in/problems/One-Edge-196

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
    ll n,m;
    cin>>n>>m;
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
    vector<ll> suffix(comp_no+1);
    suffix[comp_no]=comp_size[comp_no];
    for(int i=comp_no-1;i>=1;i--){
        suffix[i]=suffix[i+1]+comp_size[i];
    }
    ll ans=0;
    for(int i=1;i<comp_no;i++){
        ans+=comp_size[i]*suffix[i+1];
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}