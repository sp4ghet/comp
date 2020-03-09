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
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll ans = LLONG_MAX;
    rep(i, n) rep(j, n)
    {
        ll dist = 0;
        rep(k, n)
        {
            dist += abs(a[i] - a[k]);
            dist += abs(a[k] - b[k]);
            dist += abs(b[j] - b[k]);
        }

        ans = min(ans, dist);
    }

    cout << ans << endl;

    return 0;
}