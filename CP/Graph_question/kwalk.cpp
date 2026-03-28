// https://maang.in/problems/KWALK-607


#include <bits/stdc++.h>
using namespace std;
#define p pair<int,int>
#define F first
#define S second

int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	// Complete the function
    vector<vector<int>>visited(N+1,vector<int>(N+1,0));
    queue<p>q;
    q.push({Sx,Sy});
    visited[Sx][Sy]=1;
    int ans=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto t=q.front();
            q.pop();
            int x=t.F;
            int y=t.S;
            if(x==Fx&&y==Fy) return ans;
            for(int k=0;k<8;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&!visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
        ans++;
    }
    return -1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
