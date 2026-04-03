// https://maang.in/problems/maximum_area-374

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
class maxPortion{
    public:
    set<ll> points; // points where cut are done 
    multiset<ll> gaps; // length of portion stored
    maxPortion(ll w){
        // [0...w]
        points.insert(0);
        points.insert(w);
        gaps.insert(w);
    }

    void insert(int x){
        // [a...x...b]
        auto it = points.upper_bound(x);
        ll b = *it;
        it--;
        ll a = *it;
        points.insert(x);
        gaps.erase(gaps.find(b-a)); // delete one occurence of length b-a
        gaps.insert(x-a);
        gaps.insert(b-x);
    }

    ll maxLength(){ // maximum length present at the end of multiset gaps
        return *gaps.rbegin();  
    }

};
void solve(){
    // ans = (maximum on x-axis) * (maximum on y-axis)
    // solve on 1-D
    ll h,w,n;
    cin>>h>>w>>n;
    maxPortion horizontal(h), vertical(w);
    while(n--){
        char type;
        ll val;
        cin>>type>>val;
        if(type == 'H'){
            horizontal.insert(val);
        }else{
            vertical.insert(val);
        }

        cout<< horizontal.maxLength() * vertical.maxLength()<<endl;
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