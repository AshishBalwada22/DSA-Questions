// https://maang.in/problems/Find-the-Number-of-Rooms-191

#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>matrix;
vector<vector<int>>visited;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;

void dfs(int i,int j){
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0&&ni<n&&nj>=0&&nj<m&&!visited[ni][nj]&&matrix[ni][nj]!='#'){
            dfs(ni,nj);
        }
    }
}
void solve(){
    cin>>n>>m;
    matrix = vector<vector<char>>(n,vector<char>(m));
    visited = vector<vector<int>>(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            matrix[i][j]=ch;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='.'&&!visited[i][j]){
                dfs(i,j);
                ans++;
            }
        }
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