#include<bits/stdc++.h>
using namespace std;

void conquer(int crr[], int l, int mid, int r)
{
    int n = mid-l+1;
    int arr[n];
    for(int i=0, k=l; i<n; i++,k++)
    {
        arr[i] = crr[k];
    }

    int m = r-mid;
    int brr[m];
    for(int i=0, k=mid+1; i<m; i++,k++)
    {
        brr[i] = crr[k];
    }

    int i=0, j=0, curr=l;

    while (i<n && j<m)
    {
        if(arr[i] < brr[j])
            crr[curr++] = arr[i++];
        else
            crr[curr++] = brr[j++];
    }

    while (i<n)
    {
        crr[curr++] = arr[i++];
    }

    while (j<m)
    {
        crr[curr++] = brr[j++];
    }
}

void divide(int arr[], int l, int r)
{
    if(l>=r) return;

    int mid = (l+r) / 2;
    divide(arr, l, mid);
    divide(arr, mid+1, r);
    conquer(arr, l, mid, r);
}

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    divide(arr, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}