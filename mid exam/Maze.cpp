#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mov = {{0,1},{0,-1},{-1,0},{1,0}};
char grid[1005][1005];
bool visited[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];
int n, m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<4; i++)
        {
            int ci = par_i+mov[i].first;
            int cj = par_j+mov[i].second;

            if(valid(ci, cj) && !visited[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                parent[ci][cj] = par;
            }
        }
    }
    
}

int main()
{
    cin >> n >> m;

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    
    int si, sj, di, dj;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);
    // cout << level[di][dj] << endl;

    if(level[di][dj] == -1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        pair<int, int> node = {di, dj};

        while (node.first != -1 &&node.second != -1)
        {
            // cout << node.first << " " << node.second << endl;
            if(grid[node.first][node.second] == '.')
            {
                grid[node.first][node.second] = 'X';
            }
            node = parent[node.first][node.second];
        }
        

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}