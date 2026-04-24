1) foundation of tree
- traverse and subtree related
- centre, centroid, diameter related
- contribution technique on tree

2) intermediate
- ancestral related
- binary lifting 
- tree re-rooting

3) advanced
- tree dp
- euler tour on tree
- centroid decomposition
- hld on tree
- reachability

// tree defination
- connected graph(means only one component) with unique simple path between (u,v)
- connected graph with no cycle 
- n nodes connected graph with n-1 edges

// Imp note
- dfs cannot solve single source path problem in graph as shortest path can come from different path and we already marked visited that node so, we cannot explore that different path
- but in tree, we have unique simple path so we can solve it

1) traverse all node of tree using dfs
2) find distance of all node from root node
3) find diameter of tree - longest path exist in tree
4) find the centre of tree

vector<vector<int>> edges;
vector<int>dist;
vector<int>parent;

void dfs(int cur,int par,int dd){
    dist[cur]=dd;
    parent[cur]=par;
    for(auto nxt:edges[cur]){
        if(nxt!=par){
            dfs(nxt,cur,dd+1);
        }
    }
}
void solve(){
    int n,e;
    cin>>n>>e;
    edges.resize(n+1);
    dist.resize(n+1);
    parent.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // traverse all node of tree using dfs
    dfs(1,-1,0);
    // distance of all node from root node
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    // diameter of tree - longest path exist in tree
    // o(n^2)
    int ans=INT_MIN;
    for(int node=1;node<=n;node++){
        dfs(node,-1,0);
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
    }
    cout<<ans<<endl;

    // diameter of tree - o(n)
    // start from any node, find the farthest node x
    // start from node x, find the farthest node y
    // difference of x-y is always longest path or diameter

    dfs(1,-1,0);
    int x = 1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[x]) x=i;
    }
    dfs(x,-1,0);
    int y=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[y]) y=i;
    }
    cout<<dist[y]<<endl;

    // find the centre
    // tree can have 1 or 2 centre only
    // all diameter passes through centre, so centre is a mid point
    // we need parent array to go back
    if(dist[y]%2==0){
        //even distance, then only one centre is present
        int len=dist[y]%2;
        int cen=y;
        while(len--){
            cen=parent[cen];
        }
        cout<<cen<<endl;
    }else{
        //odd distance, then two centre is present
        int len=dist[y]%2;
        int cen1=y;
        while(len--){
            cen1=parent[cen1];
        }
        int cen2=parent[cen1];
        cout<<cen1<<" "<<cen2<<endl;
    }
}