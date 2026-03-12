#include <bits/stdc++.h>
using namespace std;
int n;
char grid[35][35];
bool visited[35][35];
int level[35][35];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
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

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != 'T')
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
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        int si, sj, di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (grid[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));
        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}