#include<bits/stdc++.h>
using namespace std;

int n, e;
bool visited[105];
vector<int> adj_list[105];
int parent[105];
bool cycle;

void dfs(int src)
{
    visited[src] = true;

    for(int child : adj_list[src])
    {
        if(visited[child] && parent[src] != child)
            cycle = true;
        if(!visited[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    cin >> n >> e;
    
    while(e--)
    {
        int a, b; cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    cycle = false;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    // for(int i=0; i<n; i++)
    // {
    //     cout << i << " parent: " << parent[i] << endl;
    // }

    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;
    return 0;
}