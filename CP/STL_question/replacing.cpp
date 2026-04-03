// https://atcoder.jp/contests/abc171/tasks/abc171_d

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
void solve(){
    int n;
    cin>>n;
    map<ll,ll>m; // val -> freq
    ll sum=0;
    for(int i=0;i<n;i++){
      ll val;
      cin>>val;
      m[val]++;
      sum+=val;
    }
    int q;
    cin>>q;
    while(q--){
      ll b,c;
      cin>>b>>c;
      sum= sum - b*m[b] + c*m[b];
      if(m.find(c)!=m.end()) m[c]+=m[b];
      else m.insert({c, m[b]});
      m.erase(b);
      cout<<sum<<endl;
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