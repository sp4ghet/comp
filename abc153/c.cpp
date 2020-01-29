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
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end(), greater<ll>());
    rep(i, k)
    {
        if (i == n)
        {
            break;
        }
        h[i] = 0;
    }
    ll ans = 0;
    rep(i, n)
    {
        ans += h[i];
    }

    cout << ans << endl;

    return 0;
}