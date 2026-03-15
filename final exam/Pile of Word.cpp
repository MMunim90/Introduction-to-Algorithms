#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (s1.size() != s2.size())
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            bool is_equal = true;

            for (int i = 0; i < s1.size(); i++)
            {
                if(s1[i] != s2[i])
                {
                    is_equal = false;
                    break;
                }
            }

            if(!is_equal) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

    return 0;
}