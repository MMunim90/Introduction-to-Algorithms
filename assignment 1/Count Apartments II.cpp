#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int cnt = 0;
vector<int> num;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + mov[i].first;
        int cj = sj + mov[i].second;

        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }

    return cnt;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (valid(i, j) && !visited[i][j] && grid[i][j] == '.')
            {
                int count = dfs(i, j);
                num.push_back(count);
                cnt = 0;
            }
        }
    }

    sort(num.begin(), num.end());

    if (!num.empty())
    {
        for (int i : num)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}