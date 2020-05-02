#include <bits/stdc++.h>
using namespace std;
using vint = vector<int>;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vint a(n), ans(n);
    rep(i, n) cin >> a[i];

    for (int i = n - 1; i >= 0; i--)
    {
        int now = 0;
        for (int j = i + i + 1; j < n; j += (i + 1))
        {
            now += ans[j];
        }
        ans[i] = now % 2 != a[i];
    }

    int total = 0;
    rep(i, n) total += ans[i];

    cout << total << endl;
    rep(i, n)
    {
        if (ans[i])
        {
            cout << i + 1 << endl;
        }
    }

    return 0;
}