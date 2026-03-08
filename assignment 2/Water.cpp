#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;

        int arr[n];
        int arr2[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            arr2[i] = arr[i];
        }

        sort(arr2, arr2+n, greater<int>());

        for(int i=0; i<n; i++)
        {
            if(arr2[0] == arr[i] || arr2[1] == arr[i])
                cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}