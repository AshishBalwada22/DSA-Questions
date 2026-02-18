// https://atcoder.jp/contests/abc133/tasks/abc133_c

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a,b;
  cin>>a>>b;
  if(b-a+1>=2019) cout<<0<<endl;
  else{
    ll ans = 2018;
    for(ll i=a;i<=b;i++){
      for(ll j=i+1;j<=b;j++){
        ans = min(ans, (i*j)%2019);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}