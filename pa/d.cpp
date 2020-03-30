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
    vector<char> t = {'R', 'W', 'B'};
    int n;
    cin >> n;
    vector<string> f(5);
    rep(y, 5) cin >> f[y];
    vector<vector<ll>> dp(n + 1, vector<ll>(3, INT32_MAX));

    rep(i, 3) dp[0][i] = 0;

    rep(i, n)
    {
        rep(j, 3)
        {
            int cost = 0;
            rep(y, 5)
            {
                cost += !(t[j] == f[y][i]);
            }
            rep(k, 3)
            {
                if (k == j)
                    continue;
                chmin(dp[i + 1][j], dp[i][k] + cost);
            }
        }
    }

    ll ans = min_element(dp[n].begin(), dp[n].end())[0];
    cout << ans << endl;

    return 0;
}