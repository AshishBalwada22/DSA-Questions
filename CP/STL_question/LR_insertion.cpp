// https://atcoder.jp/contests/abc237/tasks/abc237_d

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<int> dq1,dq2;
    // cutting array technique, taking middle element
    int num = 0;
    for(char ch:s){
      if(ch=='L'){
        dq2.push_front(num);
      }else if(ch=='R'){
        dq1.push_back(num);
      }
      num++;
    }
    for(auto val:dq1) cout<<val<<" ";
    cout<<num<<" ";
    for(auto val:dq2) cout<<val<<" ";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}