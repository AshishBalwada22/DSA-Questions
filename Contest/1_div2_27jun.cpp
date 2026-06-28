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