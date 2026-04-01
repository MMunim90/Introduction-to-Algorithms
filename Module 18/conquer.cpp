#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int m; cin >> m;
    int brr[m];
    for(int i=0; i<m; i++)
    {
        cin >> brr[i];
    }

    int c[n+m];

    int i=0, j=0, curr=0;

    while (i<n && j<m)
    {
        if(arr[i] < brr[j])
        {
            c[curr] = arr[j];
            i++;
            curr++;
        }
        else
        {
            c[curr] = brr[j];
            j++;
            curr++;
        }
    }
    
    while(i<n)
    {
        c[curr] = arr[i];
        i++; curr++;
    }

    while (j<m)
    {
        c[curr] = brr[j];
        j++; curr++;
    }
    
    for(int i=0; i<m+n; i++)
    {
        cout << c[i] << " ";
    }

    cout << endl;
    return 0;
}