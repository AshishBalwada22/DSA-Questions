// https://maang.in/problems/Connected-Component-Size-684

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<vector<int>>visited;
vector<vector<int>>visited1;
int n,m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs1(int i, int j, int comp_size){
    visited1[i][j]=1;
    edges[i][j]=comp_size;
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0&&ni<n&&nj>=0&&nj<m&&edges[ni][nj]==0&&!visited1[ni][nj]){
            dfs1(ni,nj,comp_size);
        }
    }
}

int dfs(int i, int j){ // return component size
    visited[i][j]=1;
    int ans=0;
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0&&ni<n&&nj>=0&&nj<m&&edges[ni][nj]==0&&!visited[ni][nj]){
            ans+=dfs(ni,nj);
        }
    }
    return ans+1;
}
void solve(){
    cin>>n>>m;
    edges = vector<vector<int>>(n,vector<int>(m));
    visited = vector<vector<int>>(n,vector<int>(m,0));
    visited1 = vector<vector<int>>(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val;
            cin>>val;
            edges[i][j]=val;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(edges[i][j]==0&&!visited[i][j]){
                int comp_size = dfs(i,j);
                if(comp_size!=1)
                dfs1(i,j,comp_size);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
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