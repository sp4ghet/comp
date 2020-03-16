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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = LLONG_MAX;
    rep(i, 1 << n)
    {
        ll now = 0;
        int m = 0;
        int ok = 0;
        rep(j, n)
        {
            if ((1 << j) & i)
            {
                now += max(0, m - a[j] + 1);
                m = max(m + 1, a[j]);
                ok++;
            }
            else
            {
                if (m < a[j])
                {
                    ok++;
                }
                m = max(m, a[j]);
            }
        }
        if (ok >= k)
        {
            ans = min(now, ans);
        }
    }

    cout << ans << endl;

    return 0;
}