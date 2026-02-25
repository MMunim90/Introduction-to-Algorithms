#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[105][105];
vector<pair<int, int>> mov = {{-1,2},{1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
char grid[105][105];
int level[105][105];

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

        for(int i=0; i<8; i++)
        {
            int ci = par_i + mov[i].first;
            int cj = par_j + mov[i].second;

            if(valid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
    
}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        cin >> n >> m;

        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;

        bfs(ki, kj);

        cout << level[qi][qj] << endl;
    }
    
    return 0;
}