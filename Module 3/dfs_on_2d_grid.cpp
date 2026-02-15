#include<bits/stdc++.h>
using namespace std;

int n,m;
char grid[105][105];
bool visited[105][105];
vector<pair<int, int>> mov = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void dfs(int src_row, int src_col)
{
    cout << src_row << " " << src_col << endl;
    visited[src_row][src_col] = true;

    for(int i=0; i<4; i++)
    {
        int ci, cj;
        ci = src_row + mov[i].first;
        cj = src_col + mov[i].second;
        // cout << ci << " " << cj << endl;

        if(valid(ci, cj) == true && !visited[ci][cj])
            dfs(ci,cj);
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[n][m];

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << grid[n][m];
    //     }
    //     cout << endl;
    // }

    int src_row, src_col;
    cin >> src_row >> src_col;

    memset(visited, false, sizeof(visited));
    dfs(src_row, src_col);
    return 0;
}