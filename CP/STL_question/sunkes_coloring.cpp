// https://atcoder.jp/contests/abc045/tasks/arc061_b

#include <bits/stdc++.h>

using namespace std;
using ll= long long;
using ld= long double;
using pll=pair<ll, ll>;
using pii=pair<int, int>;
#define inf INT_MAX/2
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
# define PI           acos(-1)
# define fst           first
# define snd           second

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll h, w;
    int n; cin>>h>>w>>n;

    map<pii, int> cnt;

    for(int i=0; i<n; ++i){
        int a, b; cin>>a>>b;

        for(int r=a-2; r<=a; ++r){
            for(int c=b-2; c<=b; ++c){
                if(r>=1 && r<=h-2 && c>=1 && c<=w-2){
                    cnt[{r, c}]++;
                }
            }
        }
    }

    vector<ll> ans(10, 0);
    ll total=(h-2)*(w-2);
    ll color=0;

    for(auto const&[pos, c]:cnt){
        ans[c]++;
        ++color;
    }

    ans[0]=total-color;

    for(int j=0; j<=9; ++j) cout<<ans[j]<<'\n';
    return 0;
}