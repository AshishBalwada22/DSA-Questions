// https://atcoder.jp/contests/abc103/tasks/abc103_c

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  // f = a1-1 + a2-1 + .. + an-1
  // f = (a1+a2+..+an) - n
  int sum=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    sum+=a;
  }
  
  cout<<sum-n<<endl;
}