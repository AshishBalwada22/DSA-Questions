// https://atcoder.jp/contests/abc148/tasks/abc148_e

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
  ll n;
  cin>>n;
  if(n%2!=0){
    cout<<0<<endl;
    return 0;
  }
  // f(n) = n(n-2)(n-4)..
  // f(10) = 10.8.6.4.2.f(1) = 10.8.6.4.2.1 = 2^(10/2) * (5.4.3.2.1) = 2^(n/2) * (n/2)!
  // if n is odd, then it won't contribute any trailing zero
  // if n is even, then 10 is a factor of 2*5 , how many number of 5 is present in (n/2)! would be my answer
  // power of any prime number p in n! = n/p + n/(p^2) + n/(p^3) + .. + 0
  n=n/2;
  ll ans=0;
  while(n!=0){
    ans+=(n/5);
    n=n/5;
  }
  cout<<ans<<endl;
  return 0;
}
