#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
int main()
{
    ll n, k, s;
    cin >> n >> k >> s;

    ll val = s == 1000000000 ? 1 : s + 1;
    rep(i, n)
    {
        if (i < k)
        {
            cout << s;
        }
        else
        {
            cout << val;
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}