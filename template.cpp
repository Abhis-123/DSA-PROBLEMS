#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    vector<int> prefix(n, 0);
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (sum >= arr[i])
        {
            prefix[i] = 1;
        }
        sum = arr[i] + sum;
    }

    if (prefix[n - 1] == 0)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        int res = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (prefix[i] == 1)
                res++;
        }
        cout << res << endl;
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
