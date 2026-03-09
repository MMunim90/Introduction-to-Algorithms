#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edlist;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        c = -1 * c;

        edlist.push_back(Edge(a, b, c));
    }

    ll pinf = 1e17;
    ll ninf = -1 * pinf;

    vector<ll> dist(n + 1, pinf);

    dist[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // structure binding
        for (auto obj : edlist)
        {
            int a = obj.u;
            int b = obj.v;
            int c = obj.c;
            if (dist[a] == pinf)
                continue;
            dist[b] = min(dist[b], dist[a] + c);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto obj : edlist)
        {
            int a = obj.u;
            int b = obj.v;
            int c = obj.c;
            if (dist[a] == pinf)
                continue;
            if (dist[a] + c < dist[b])
            {
                dist[b] = ninf;
            }
        }
    }

    if (dist[n] == ninf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[n] * -1 << endl;
    }

    return 0;
}