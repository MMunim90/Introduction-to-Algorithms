#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;

    bool is_lucky = false;

    while(n>0)
    {
        int num = n%10;
        n /= 10;
        if(num == 7)
        {
            is_lucky = true;
            break;
        }
    }

    if(is_lucky) cout << "Lucky" << endl;
    else cout << "Not Lucky" << endl;
    return 0;
}