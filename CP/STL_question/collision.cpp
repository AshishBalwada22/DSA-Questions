// https://maang.in/problems/collision-82

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    // xi/vi = yi/ui , time taken would be the same
    // xi*ui = vi*yi
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x,u;
        cin>>x>>u;
        mp[x*u]++;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int y,v;
        cin>>y>>v;
        if(mp.find(y*v)!=mp.end()){
            mp[y*v]--;
            if(mp[y*v]==0) mp.erase(y*v);
            ans++;
        }
    }
    cout<<ans<<endl;
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