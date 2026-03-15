#include<bits/stdc++.h>
using namespace std;
int dp[100005];

bool make_it(int start, int end)
{
    if(start == end)
    {
        return true;
    }
    else if(start > end)
    {
        return false;
    }

    if(dp[start] != -1)
        return dp[start];

    bool res1 = make_it(start+3, end);
    bool res2 = make_it(start*2, end);

    dp[start] = res1 || res2;
    return dp[start];
}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;

        for(int i=0; i<n; i++)
            dp[i] = -1;

        if(make_it(1, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}