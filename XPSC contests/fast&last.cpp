#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);

    for(int i=1; i<=n; i++)
    {
        cin >> v1[i];
        v2[i] = v1[i];
    }


    sort(v2.begin(), v2.end());

    
    for(int i=1; i<=n; i++)
    {
        auto it = find(v1.begin(), v1.end(), v2[i]);

        cout << v2[i] << " " << *it << endl;
    }

    return 0;
}