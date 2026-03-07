#include<bits/stdc++.h>
using namespace std;

int leader[1005];
int group_size[1005];

int find(int node)
{
    if(leader[node] == -1) return node;

    int lead = find(leader[node]);
    leader[node] = lead;
    return lead;
}

void dsu_union(int node1, int node2)
{
    int lead1 = find(node1);
    int lead2 = find(node2);

    if(group_size[lead1] >= group_size[lead2])
    {
        leader[lead2] = lead1;
        group_size[lead1] += group_size[lead2];
    }
    else
    {
        leader[lead1] = lead2;
        group_size[lead2] += group_size[lead1];
    }
}

int main()
{
    memset(leader, -1, sizeof(leader));
    memset(group_size, 1, sizeof(group_size));

    int n,e;
    cin >> n >> e;
    bool cycle = false;

    while (e--)
    {
        int a, b; cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA == leaderB)
            cycle = true;
        else
            dsu_union(a, b);
    }
    
    if(cycle) cout << "Cycle detected in the graph" << endl;
    else cout << "No cycle detected in the graph" << endl;
    return 0;
}