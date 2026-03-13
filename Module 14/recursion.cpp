// print 1 to 5 with recursion

// #include<bits/stdc++.h>
// using namespace std;

// void rec(int n)
// {
//     if(n == 0) return;
//     rec(n-1);
//     cout << n << " ";
// }

// int main()
// {
//     int n; cin >> n;
//     rec(n);
//     return 0;
// }


// sum 1 to 5 with recursion

#include<bits/stdc++.h>
using namespace std;

int rec(int n)
{
    if(n > 5) return 0;

    int sum = rec(n+1);
    return sum + n;
}

int main()
{
    cout << rec(1) << endl;
    return 0;
}