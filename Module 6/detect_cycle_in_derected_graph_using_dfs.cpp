#include<bits/stdc++.h>
using namespace std;

int n,e;
bool visited[105];
vector<int> adj_list[105];
bool path_visit[105];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    path_visit[src] = true;

    for(int child : adj_list[src])
    {
        if(visited[child] && path_visit[child])
        {
            cycle = true;
        }

        if(!visited[child])
        {
            dfs(child);
        }
    }

    path_visit[src] = false; 
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a,b; cin >> a >> b;
        adj_list[a].push_back(b);
    }
    
    memset(visited, false, sizeof(visited));
    memset(path_visit, false, sizeof(path_visit));

    cycle = false;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;
    return 0;
}