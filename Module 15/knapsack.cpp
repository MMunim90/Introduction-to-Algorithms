#include<bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];

int knapsack(int i, int max_weight)
{
    if(i<0 || max_weight <= 0) return 0;

    if(weight[i] <= max_weight)
    {
        // 2 options
        // 1. put item in the bag, 2. cannot put item in the bag.
        int opt1 = knapsack(i-1, max_weight - weight[i]) + val[i];
        int opt2 = knapsack(i-1, max_weight);
        return max(opt1, opt2);
    }
    else
    {
        // 1 option
        // cannot put item in the bag.
        return knapsack(i-1, max_weight);
    }
}

int main()
{
    int n, max_weight;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> val[i];
    for(int i=0; i<n; i++)
        cin >> weight[i];

    cin >> max_weight;

    cout << knapsack(n-1, max_weight) << endl;

    return 0;
}