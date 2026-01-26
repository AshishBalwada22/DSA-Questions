// https://codeforces.com/problemset/problem/776/B

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl<<1;
        return 0;
    }else if(n==2){
        cout<<1<<endl<<1<<" "<<1;
        return 0;
    }
    
    vector<int> isprime(n+2,1);
    for(int i=2;i*i<=n+1;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n+1;j+=i){
                isprime[j]=0;
            }
        }
    }
    cout<<"2"<<endl;
    for(int i=2;i<=n+1;i++){
        if(isprime[i]) cout<<1<<" ";
        else cout<<2<<" ";
    }
    return 0;
}