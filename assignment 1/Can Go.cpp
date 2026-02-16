#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> mov = {{1,0}, {-1,0}, {0,1}, {0,-1}};
char grid[1005][1005];
bool visited[1005][1005];

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
        int ci = si + mov[i].first;
        int cj = sj + mov[i].second;

        if(valid(ci, cj) && !visited[ci][cj] && (grid[ci][cj]=='.' || grid[ci][cj]=='A' || grid[ci][cj]=='B'))
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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    dfs(si, sj);

    if(visited[di][dj] == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}