#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)

ll nc2(ll n)
{
    return n * (n - 1) / 2;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    rep(i, n)
    {
        int k;
        cin >> k;
        m[k]++;
        a[i] = k;
    }

    ll ans = 0;
    for (auto k : m)
    {
        ans += nc2(k.second);
    }

    for (auto k : a)
    {
        int cnt = m[k] - 1;
        cout << (ans - cnt) << endl;
    }

    return 0;
}