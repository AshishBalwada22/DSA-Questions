// Ancestor data structure

1) for every node x, find maximum value of max(abs(val[x]-val[p])) where p is a ancestor of x
- if we want maximum value then we need to maintain fathest value that is the minimum and maximum value of ancestor

#define INF 1e9
vector<vector<int>> edges;
vector<int>arr; // every node has some weight
int n;
vector<int>ans;

void dfs(int cur,int par, int minseen, int maxseen){
    ans[cur]=max(abs(arr[cur]-minseen),abs(arr[cur]-maxseen));
    for(auto nxt:edges[cur]){
        if(nxt!=par){
            dfs(nxt,cur,min(minseen,arr[cur]),max(maxseen,arr[cur]));
        }
    }
}
void solve(){
    int e;
    cin>>n>>e;
    edges.resize(n+1);
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ans.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
   dfs(1,-1,INF,-INF);
   // find the maximum value of max(abs(val[x]-val[p])) where p is a ancestor of x
   for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
   }
}


2) find the minimum value of abs(val[x]-val[p])
- in case of minimum value, we need to maintain the closest value of x, for that we need to maintain every value in the set and then can apply lower_bound

#define INF 1e9
vector<vector<int>> edges;
vector<int>arr; // every node has some weight
int n;
vector<int>ans;

void dfs(int cur,int par, multiset<int>&mt){
    auto it = mt.lower_bound(arr[cur]);
    int maxval=INF,minval=-INF;
    if(it!=mt.end()) maxval = *it;
    if(it!=mt.begin()){
        it--;
        minval=*it;
    }
    
    ans[cur] = min(arr[cur]-minval,maxval-arr[cur]);
    mt.insert(arr[cur]);
    for(auto nxt:edges[cur]){
        if(nxt!=par){
            dfs(nxt,cur,mt);
        }
    }
    mt.erase(mt.find(arr[cur]));
}
void solve(){
    int e;
    cin>>n>>e;
    edges.resize(n+1);
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ans.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
   multiset<int>mt;
   dfs(1,-1,mt);
   // find the minimum value of max(abs(val[x]-val[p])) where p is a ancestor of x
   for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
   }
}

