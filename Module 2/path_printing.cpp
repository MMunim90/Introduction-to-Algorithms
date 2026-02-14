#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parents[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();


        for(int child : adj_list[par])
        {
            if(visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                parents[child] = par;
            }
        }
    }
    
}

void print_path(int node, int dst)
{
    if(node == -1)
        return;
    
    print_path(parents[node], dst);
    cout << node;
    if(node != dst)
        cout << " -> ";
}

int main()
{
    int n,e; cin >> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parents, -1, sizeof(parents));

    int src, dst; cin >> src >> dst;
    bfs(src);

    // for(int i=0; i<n; i++)
    // {
    //     cout << i << " child of " << parents[i] << endl;
    // }
    // cout << level[dst] << endl;

    int node = dst;

    // this loop printing the path in reverse way
    // while (node != -1)
    // {
    //     cout << node << " ";
    //     node = parents[node];
    // }

    // for printing in right way i use a recursive function.
    print_path(node, dst);
    
    
    return 0;
}