// traverse all node using dfs

vector<vector<int>> edges;

void dfs(int cur,int par){
    cout<<cur<<endl;
    for(auto nxt:edges[cur]){ // need to maintain parent only, no need to maintain visited array as graph has no cycle
        if(nxt!=par){
            dfs(nxt,cur);
        }
    }
}
void solve(){
    int n,e;
    cin>>n>>e;
    edges.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,-1);
}

// find the distance of all node from root node

vector<vector<int>> edges;
vector<int>dist;

void dfs(int cur,int par){
    if(par!=-1){
        dist[cur]=dist[par]+1;
    }
    for(auto nxt:edges[cur]){
        if(nxt!=par){
            dfs(nxt,cur);
        }
    }
}
void solve(){
    int n,e;
    cin>>n>>e;
    edges.resize(n+1);
    dist.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}