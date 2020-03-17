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
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> ba(n);
    rep(i, n)
    {
        ll k = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ba[i] = k;
    }
    rep(i, n - 1)
    {
        ba[i + 1] += ba[i];
    }

    ll ans = 0;
    rep(i, n)
    {
        ll k = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
        if (k > 0)
        {
            ans += ba[k - 1];
        }
    }
    cout << ans << endl;

    return 0;
}
