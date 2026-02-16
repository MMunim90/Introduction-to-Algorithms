#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e; cin >> n >> e;
    vector<int> adj_list[n];

    while (e--)
    {
        int a, b; cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q; cin >> q;

    while (q--)
    {
        int x; cin >> x;
        vector<int> des;
        for(int i : adj_list[x])
        {
            des.push_back(i);
        }

        if(des.empty())
        {
            cout << "-1" << endl;
            continue;
        }

        sort(des.begin(), des.end(), greater<int>());

        for(int i : des)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}