#include<bits/stdc++.h>
using namespace std;

// time complexity - O(2^N)
int fibo(int n)
{
    // 1
    // if(n==0) return 0;
    // if(n==1) return 1;

    // 2
    // if(n == 0 || n == 1)
    //     return n;

    // 3
    if(n < 2) return n;

    return fibo(n-1) + fibo(n-2);
}

int main()
{
    int n; cin >> n;
    cout << fibo(n);

    // for(int i=0; i<10; i++)
    // {
    //     cout << fibo(i) << " ";
    // }
    return 0;
}