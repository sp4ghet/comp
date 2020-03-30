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

struct cloth
{
    int l, u, c;
    cloth(int l = 0, int u = 0, int c = 0) : l(l), u(u), c(c) {}
};

int main()
{
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    rep(i, d) cin >> t[i];
    vector<cloth> c(n + 1);

    rep(i, n) cin >> c[i].l >> c[i].u >> c[i].c;

    vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT32_MIN));
    rep(i, n)
    {
        if (t[0] < c[i].l || t[0] > c[i].u)
            continue;
        dp[1][i] = 0;
    }
    for (int i = 1; i < d; ++i)
        rep(j, n) rep(k, n)
        {
            if (t[i] < c[j].l || t[i] > c[j].u)
                continue;

            chmax(dp[i + 1][j], dp[i][k] + abs(c[k].c - c[j].c));
        }

    int ans = max_element(dp[d].begin(), dp[d].end())[0];

    cout << ans << endl;

    return 0;
}