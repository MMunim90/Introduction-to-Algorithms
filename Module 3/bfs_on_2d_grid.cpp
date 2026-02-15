#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int, int>> mov = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool visited[105][105];
char grid[105][105];
int dist[105][105];

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty()) 
    {
        pair<int,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        // cout << par_i << " " << par_j << endl;

        for(int i=0; i<4; i++)
        {
            int ci = par_i + mov[i].first;
            int cj = par_j + mov[i].second;

            if(!visited[ci][cj] && valid(ci,cj))
            {
                q.push({ci,cj});
                visited[ci][cj] = true;
                dist[ci][cj] = dist[par_i][par_j]+1;
            }
        }
    }
    
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    
    int si, sj, di, dj; 
    cin >> si >> sj >> di >> dj;
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    bfs(si, sj);
    cout << dist[di][dj] << endl;
    return 0;
}