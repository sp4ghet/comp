#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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
    int n, d, a;
    cin >> n >> d >> a;
    vector<P> mons(n, P(0, 0));
    vector<ll> dec(n + 1, 0);
    rep(i, n) cin >> mons[i].first >> mons[i].second;

    sort(mons.begin(), mons.end());

    ll ans = 0;

    int j = 0;
    rep(i, n)
    {
        P now = mons[i];
        while (j < n && mons[j].first <= now.first + 2 * d)
        {
            j++;
        }

        now.second -= a * dec[i];
        int times = (now.second + a - 1) / a;
        times = max(times, 0);
        ans += times;
        dec[i] += times;
        // since the condition in the loop holds up to j-1
        // monster j does not get hit, but we increment anyways with the dp.
        // To account for this, subtract from monster j so all monsters up to j-1 "gets hit"
        // but monster j doesn't receive this damage because we subtract
        dec[j] -= times;
        dec[i + 1] += dec[i];
    }

    cout << ans << endl;

    return 0;
}