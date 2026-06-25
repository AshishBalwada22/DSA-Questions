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

3) Find the sum of distance of all pair of node
f(u) = summation(dist(x,u)), 1<=x<=n, find f(u) for all node

vector<vector<int>>edges;
vector<int>distt;
vector<int>subsz;
vector<int>ans;
int n;

void dfs1(int cur, int par, int dis){ // calculate distance of root node to all node, also calculate the subsize(number of node in that subtree) of node in post order
    distt[cur] = dis;
    subsz[cur]=1;
    for(auto nxt : edges[cur]){
        if(nxt!=par){
            dfs1(nxt,cur,dis+1);
            subsz[cur]+=subsz[nxt];
        }
    } 
}

void dfs2(int cur, int par, int curans){ // re-rooting, let's say node x is a root and node y is a child, if we re-root x to y, then how many times the edge between x and y is counted now
// number of node present in x subtree, for all those nodes, distance that is contributed to the answer would be incremented by 1 for all node, as root shifted to node y
// number of node present in y subtree, for all those nodes, distance would be decremented by 1 for all node
// ans[y] = ans[x] - subsize[y] + (n-subsize[y])
    ans[cur]=curans;
    for(auto nxt:edges[cur]){
        if(nxt!=par){
            dfs2(nxt,cur,curans-subsz[nxt]+(n-subsz[nxt]));
        }
    }
}

void solve(){
    int edge;
    cin>>n>>edge;
    edges.resize(n+1);
    distt.resize(n+1,0);
    subsz.resize(n+1,0);
    ans.resize(n+1,0);
    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs1(1,0,0);
    int anss = 0;
    for(int i=1;i<=n;i++){
        anss+=distt[i];
    }
    dfs2(1,0,anss);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}


