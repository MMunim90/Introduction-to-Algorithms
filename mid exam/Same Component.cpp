#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1005][1005];
vector<pair<int,int>> mov = {{0,1},{0,-1},{1,0},{-1,0}};
char grid[1005][1005];

bool valid(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si+mov[i].first;
        int cj = sj+mov[i].second;

        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    
    memset(visited, false, sizeof(visited));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    dfs(si, sj);

    if(visited[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}