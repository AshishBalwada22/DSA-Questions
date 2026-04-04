// ALgorithms
/*
single source shortest path -> BFS will solve, DFS not

single source shortest path (sssp)
- BFS -> o(v+e)
- 0-1 BFS -> o(v+e) , edges weight {0,1}
- Dijkstra -> o((v+e)log(v)) , edges weight +ve
- Bellman Ford -> o(v*e) , edges weight +ve,-ve

All Pair Shortest Path (APSP)
- Floyd Warshall -> o(v^3) , edges weight +ve,-ve

edges : 0....v ... v(squarerootof(v)) ..................v^2
        ....sparse graph............|..dense graph......|
*/

// 0-1 BFS

void bfs(int x,vector<vector<pair<int,int>>>&edges,vector<int>&visited,vector<int>&distance){
    deque<int>dq; 
    // dq =>    0-edge weight(push_front)   | 1-edge weight(push_back)
    dq.push_back(x); 
    distance[x]=0;
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        if(visited[cur]) continue; // if node is already visited, then why explore all the path via node again
        visited[cur]=1; // marking visited while popping to ensure that we have explored all the path as there might be smallest distance come from different path
        for(auto [nxt,w] : edges[cur]){
            if(!visited[nxt] && distance[cur]+w<=distance[nxt]){ // edge relaxation
                distance[nxt] = distance[cur]+w;
                if(w==0){
                    dq.push_front(nxt);
                }else{
                    dq.push_back(nxt);
                }
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>edges(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    vector<int>visited(n+1,0);
    vector<int>distance(n+1,INT_MAX);
    bfs(1,edges,visited,distance);
    for(int dist : distance){
        cout<<dist<<" ";
    }
}


