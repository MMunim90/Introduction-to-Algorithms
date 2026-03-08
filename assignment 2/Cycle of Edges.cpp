#include<bits/stdc++.h>
using namespace std;

int leader[1000005];
int group_size[1000005];

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
    int count = 0;

    while (e--)
    {
        int a, b; cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA == leaderB)
            count++;
        else
            dsu_union(a, b);
    }
    
    cout << count << endl;
    return 0;
}