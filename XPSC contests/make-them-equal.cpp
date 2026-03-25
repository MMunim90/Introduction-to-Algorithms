#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        string a;
        string b;

        for(int i=0; i<n; i++)
        {
            if(k == 0) break;
            if(a[i] != b[i])
            {
                if(a[i] == '1' && b[i] == '0')
                {
                    b[i] = '1';
                    k--;
                }
                else if(a[i] == '0' && b[i] == '1')
                {
                    b[i] = '0';
                    k--;
                }
            }
        }

        bool is_equal = true;

        for(int i=0; i<n; i++)
        {
            if(a[i] != b[i])
            {
                is_equal = false;
                break;
            }
        }

        if(is_equal) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}