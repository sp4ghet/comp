#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int x, y, ac, bc, cc;
    cin >> x >> y >> ac >> bc >> cc;
    vector<int> a(ac), b(bc), c(cc);
    rep(i, ac) cin >> a[i];
    rep(i, bc) cin >> b[i];
    rep(i, cc) cin >> c[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    ll ans = 0;
    int ci = 0, ai = 0, bi = 0;
    rep(i, x + y)
    {
        if (bi >= y || a[ai] > b[bi] && ai < x)
        {
            if (ci < cc && c[ci] > a[ai])
            {
                ans += c[ci];
                ci++;
            }
            else
            {
                ans += a[ai];
                ai++;
            }
        }
        else
        {
            if (ci < cc && c[ci] > b[bi])
            {
                ans += c[ci];
                ci++;
            }
            else
            {
                ans += b[bi];
                bi++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}