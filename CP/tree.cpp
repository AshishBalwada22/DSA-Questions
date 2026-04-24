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

