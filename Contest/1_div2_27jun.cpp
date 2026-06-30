1) https://codeforces.com/contest/2240/problem/A


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
void solve(){
    int n,k;
    cin>>n>>k;
    // a1 + a2 + ....... + ak <= n , need to maximize the  sum of bits set in all numbers pick
    if(k>=n){ // can pick max k element whose sum is equal to n
        cout<<n<<endl;
    }else{
        int sum_taken = 0;
        ll count_bit_set = 0;
        for(int i=0;i<=31;i++){
            // iterate over all bits, single bit contribute (1<<i) = (2^i) cost to cur_sum_taken
            // calculate how many times, we can set the bit, start from lsb to msb
            // find out how many times we can afford to set the bit at ith position
            int bit_value = (1<<i);
            int times = (n-sum_taken)/bit_value;
            int value_times = min(k,times); // but we know, we can set that particular bit for max k element
            if(value_times == 0) // if we can't afford even single time
            break;
            count_bit_set += value_times;
            sum_taken += bit_value * value_times;
        }
        cout<< count_bit_set<<endl;
    }
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


2) https://codeforces.com/contest/2240/problem/B

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 998244353;

ll power(ll base, ll exp){
    ll ans = 1;
    while(exp>0){
        if(exp%2==1){
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        exp=exp/2;
    }
    return ans;
}
void solve(){
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    /*
    logic - prefix xor sum
    if we need to calculate xor sum till p[r][c]
    p[r][c] = A[r][c]^p[r-1][c]^p[r][c-1]^p[r-1][c-1]
    // [r-1][c-1] added two times so, xor with [r-1][c-1] again as we know x^x = 0
    number of ways = 2^(n*m) , either choose 0 or 1
    if A[r][c] = 0, p[r][c] = p[r-1][c]^p[r][c-1]^p[r-1][c-1], as x^0=x
    number of free choice = (r-1)*m + n*(c-1) - (r-1)*(c-1)
    number of ways = 2 ^ (number of free choice)
    */
    ll exp = (r-1)*m + n*(c-1) - (r-1)*(c-1);
    cout<<power(2,exp)<<endl;
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


3) https://codeforces.com/contest/2240/problem/C