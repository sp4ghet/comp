#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
template <typename T>
void view(const std::vector<T> &v)
{
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        view(v);
    }
}
#pragma endregion

int main()
{
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> c(n);
    rep(i, n - 1) cin >> c[i + 1];
    sort(c.begin(), c.end());

    ll ans = 0;
    vector<int> p(m);
    rep(i, m) cin >> p[i];

    rep(i, m)
    {
        int k = lower_bound(c.begin(), c.end(), p[i]) - c.begin();

        int cst = INT32_MAX;

        if (k < n)
        {
            cst = min(cst, abs(p[i] - c[k]));
        }
        if (k > 0)
        {
            cst = min(cst, abs(p[i] - c[k - 1]));
        }
        cst = min(cst, abs(p[i] - c[n - 1]));
        cst = min(cst, abs(d - p[i]));

        // cout << k << " " << n << " ";
        // cout << cst << endl;
        ans += cst;
    }

    cout << ans << endl;

    return 0;
}