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
#pragma region chminmax
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

int main()
{
    int n, m;
    cin >> n >> m;
    do
    {
        vector<int> c(m);
        rep(i, m) cin >> c[i];
        vector<int> x(n);
        rep(i, n) cin >> x[i];

        vector<vector<ll>> dp(n + 1, vector<ll>(256, INT32_MAX));
        dp[0][128] = 0;
        rep(i, n) rep(j, m) rep(k, 256)
        {
            int p = min(255, max(0, k + c[j]));
            ll d = x[i] - p;

            chmin(dp[i + 1][p], dp[i][k] + d * d);
        }

        ll ans = min_element(dp[n].begin(), dp[n].end())[0];

        cout << ans << endl;
        cin >> n >> m;
    } while (n != 0 && m != 0);

    return 0;
}