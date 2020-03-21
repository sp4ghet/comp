#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> fib(n + 1, 1);
    rep(i, n - 1)
    {
        fib[i + 2] = fib[i] + fib[i + 1];
    }

    cout << fib[n] << endl;

    return 0;
}