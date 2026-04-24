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
int n;
vector<int>dist;
vector<int>parent;
vector<int>subsz;
int ansp=0;

void dfs(int cur,int par,int dd){
    dist[cur]=dd;
    parent[cur]=par;
    subsz[cur]=1;// include myself
    for(auto nxt:edges[cur]){
        if(nxt!=par){
            dfs(nxt,cur,dd+1);
            subsz[cur]+=subsz[nxt]; // add into myself after calculated for children
            ansp+=subsz[nxt]*(n-subsz[nxt]);// this is for how many times edge will be counted or part of path, contribution technique
        }
    }
}
void solve(){
    int e;
    cin>>n>>e;
    edges.resize(n+1);
    dist.resize(n+1);
    parent.resize(n+1);
    subsz.resize(n+1);
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
    // if start from anywhere and end anywhere then find the minimum number of edges traverse
    // ans = 2*e - max_distance(x,y)
    cout<<2*e-dist[y]<<endl;

    // size of subtree
    // we need vector for storing subtree size
    ansp=0;
    dfs(1,-1,0);
    for(int i=1;i<=n;i++){
        cout<<subsz[i]<<" ";
    }
    cout<<endl;

    // find the sum of distance of all pair of node
    cout<<ansp<<endl;
}

5) start from anywhere and end anywhere, visit each node exactly once. find the minimum no. of edges traverse
- then we need to traverse from two farthest node so that number of edges traverse will be minimum
- if start and end at same point then this is called euler tour
- if n nodes, (n-1) edges => (n-1)*2 edges traverse in euler tour
- if we have two farthest node, then i will go to second node and then come back to same starting node
- so path = 2*(n-1) - distance(x,y) = 2E-D
- if want to minimize the path, then distance(x,y) would be maximum, so we need to find two farthest node

6) find the size of subtree of each node

7) centroid of tree - if we remove a particular node, then size of each component should be less than or equal to n/2
- subsz[child]<=n/2

8) contribution technique on tree
find the sum of distance of all pair of node
- calculate how many times any edges would be counted or how many path of edge will be part of
- subsz[cur]*(total_nodes-subsz[cur])


