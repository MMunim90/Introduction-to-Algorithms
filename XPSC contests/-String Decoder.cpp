#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        for(int i=0; i<str.size(); i+=2)
        {
            for(int j=0; j<str[i+1]-48; j++)
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
    
    return 0;
}