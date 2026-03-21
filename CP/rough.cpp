#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void divisor(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      cout<<i<<endl;
      if(n/i!=i)// factor lies in second half
      cout<<n/i<<endl;
    }
  }
}

void primeFactorization(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int expo=0;
            while(n%i==0){
                n=n/i;
                expo++;
            }
            cout<<i<<"^"<<expo<<" ";
        }
    }
    if(n!=1) cout<<n; // this is for prime number lies in second half
}

void sieve_of_eratothenesis(int n){
    vector<int> isprime(n+1,1);
    isprime[0]=isprime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j=j+i){
                isprime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            cout<<i<<" ";
        }
    }
}


void smallest_prime_factor(int n){
    vector<int> spf(n+1);
    for(int i=0;i<=n;i++) spf[i]=i;

    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j=j+i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    // prime factor of any number from 1 to n
    int x=24;
    while(x!=1){
      cout<<spf[x]<<" ";
      x=x/spf[x];
    }
}

int mod = 1e9+7;
int binPow(int a, int p)
{
   if(p==0) return 1;
   if(p%2==0) return (binPow(a,p/2)*binPow(a,p/2))%mod;
   else return (a*binPow(a,p-1))%mod;
}

int main(){
    //cout<<gcd(5,10);
    //divisor(24);
    //primeFactorization(24);
    //sieve_of_eratothenesis(24);
    //smallest_prime_factor(25);
    cout<<binPow(2,10);
}