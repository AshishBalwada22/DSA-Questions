// Graph

// DFS - rechable, component coloring, bipartite, cycle detection 

// Question 1

/* we have n students and m relationships 
1) x student get gossips. how many students will know the gossip? 
2) solve for 1<=x<=n
*/

// solution -  component coloring/numbering

vector<vector<int>>g;
vector<int>visited;
vector<int>comp; // node lies in which component
int comp_size = 0;

void dfs(int node, int comp_no){
    visited[node]=1;
    comp[node]=comp_no;
    for(auto neigh:g[node]){
        if(!visited[neigh]){
            dfs(neigh,comp_no);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    comp.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp_no=0; // how many components are present
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            comp_no++;
            dfs(i,comp_no); // i will number/color each node in this particular component with comp_no
        }
    }
    vector<int>comp_size(comp_no+1,0); // stores size of each component
    for(int i=1;i<=n;i++){
        comp_size[comp[i]]++; // comp[i] will give node lie in which component
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<comp_size[comp[i]]<<endl;
    }

}

// if we have given two student, if x knows the gossip then can y will get to know the gossip?
if(comp[x]==comp[y]) then yes


// Question 2
/*
Given N students and M friendship, find graph is bipartite or not, graph is bipartite if and only if no two friends lie in the same section
odd cycle is not bipartite
even cycle is bipartite
*/

vector<vector<int>>g;
vector<int>visited;
vector<int>color; 
bool is_bipartite=1;

void dfs(int node, int col){
    visited[node]=1;
    color[node]=col;
    for(auto neigh:g[node]){
        if(!visited[neigh]){
            dfs(neigh,3-col); // if cur_node is colored with 1, then pass 2 or vice versa
        }else if(color[neigh]==color[node]){
            is_bipartite = 0;
            return;
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    color.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,1);
        }
    }
    if(is_bipartite){
        for(int i=1;i<=n;i++){
            cout<<i<<" "<<color[i]<<endl;
        }
    }else{
        cout<<"graph is not bipartite"<<endl;
    }
}

// Limitation of DFS - Not exploring other path of node, if already visited.

// BFS - shortest path, topological sort

// question 1 - Labyrinth, CSES SET - https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define F first
#define S second
#define state pair<int,int>

vector<vector<char>>matrix;
vector<vector<int>>visited;
vector<vector<int>>dist;
vector<vector<state>>parent;
int n,m;

bool is_valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && matrix[x][y]!='#'){
        return true;
    }
    return false;
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<state> neighbours(state cur){
    vector<state>neigh;
    for(int dir=0;dir<4;dir++){
        int x = cur.F + dx[dir];
        int y = cur.S + dy[dir];
        if(is_valid(x,y)){
            neigh.push_back({x,y});
        }
    }
    return neigh;
}

void bfs(state st){
    visited = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF)); 
    parent = vector<vector<state>>(n,vector<state>(m,{-1,-1})); 
    queue<state>q;
    q.push(st);
    dist[st.F][st.S]=0;
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        // process each node exactly once
        if(visited[cur.F][cur.S]) continue;
        visited[cur.F][cur.S] = 1;

        for(auto neigh : neighbours(cur)){
            if(!visited[neigh.F][neigh.S] && dist[cur.F][cur.S] + 1 < dist[neigh.F][neigh.S]){
                q.push(neigh);
                dist[neigh.F][neigh.S] = dist[cur.F][cur.S] + 1;
                parent[neigh.F][neigh.S] = {cur.F,cur.S};
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    matrix.resize(n,vector<char>(m));
    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]=='A'){
                st = {i,j};
            }else if(matrix[i][j]=='B'){
                en = {i,j};
            }
        }
    }
    
    bfs(st);
    if(dist[en.F][en.S]==INF) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    cout<<dist[en.F][en.S]<<endl;
    vector<state> path;
    state cur = en;
    while(cur!=make_pair(-1,-1)){
        path.push_back(cur);
        cur=parent[cur.F][cur.S];
    }
    reverse(path.begin(),path.end());

    map<string,char>m; // store diff (x1-x2,y1-y2) => direction 
    m.insert({"0,1",'L'});
    m.insert({"0,-1",'R'});
    m.insert({"-1,0",'D'});
    m.insert({"1,0",'U'});
    string ans="";
    for(int i=0;i<path.size()-1;i++){
        int x1=path[i].F;
        int x2=path[i+1].F;
        int y1=path[i].S;
        int y2=path[i+1].S;
        int xdiff = x1-x2;
        int ydiff = y1-y2;
        string cord = to_string(xdiff)+","+to_string(ydiff);
        ans.push_back(m[cord]);
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}