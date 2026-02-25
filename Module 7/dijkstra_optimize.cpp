#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[1005];
int dis[1005];

// complexity => O(V+E)
void dijkstra(int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int,int> par = pq.top();
        pq.pop();

        int par_dist = par.first;
        int par_node = par.second;

        for(auto child : adj_list[par_node])
        {
            int child_dist = child.first;
            int child_node = child.second;

            if(par_dist + child_dist < dis[child_node])
            {
                dis[child_node] = par_dist + child_dist;
                pq.push({dis[child_node], child_node});
            }
        }
    }
    
}

int main()
{
    int n,e; cin >> n >> e;
    while (e--)
    {
        int a, b, c; cin >> a >> b >> c;

        adj_list[a].push_back({c,b});
        adj_list[b].push_back({c,a});
    }
    

    for(int i=0; i<n; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    for(int i=0; i<n; i++)
        cout << i << " -> " << dis[i] << endl;
    return 0;
}