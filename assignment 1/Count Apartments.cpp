#include<bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> mov = {{1,0},{-1,0},{0,1},{0,-1}};

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
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

        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj]=='.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> grid[i][j];

    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(valid(i,j) && !visited[i][j] && grid[i][j] == '.')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}