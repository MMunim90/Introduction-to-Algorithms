#include<bits/stdc++.h>
using namespace std;

int n,e; 
bool visited[1005];
vector<int> adj_list[1005];
int parent[1005];
bool cycle;

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << par << endl;

        for(int child : adj_list[par])
        {
            if(visited[child] && parent[par] != child)
                cycle = true;

            if(!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
    
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            bfs(i);
    }

    if(cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
        
    return 0;
}