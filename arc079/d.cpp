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

vector<int> dp(10, -1);
int h, w, c[10][10];
int dfs(int i, vector<int> p = vector<int>())
{
    if (dp[i] >= 0)
    {
        return dp[i];
    }
    int closest = c[i][1];
    p.emplace_back(i);
    rep(k, 10)
    {
        if (k == i)
            continue;
        if (k < i)
            closest = min(closest, dp[k] + c[i][k]);
        else
            closest = min(closest, dfs(k, p) + c[i][k]);
    }
    if (p.size() == 1)
        dp[i] = closest;
    return closest;
}

int main()
{
    cin >> h >> w;
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w)
    {
        cin >> a[i][j];
        a[i][j] = a[i][j] == -1 ? 1 : a[i][j];
    }

    dp[1] = 0;
    rep(i, 10)
    {
        dp[i] = dfs(i, vector<int>());
    }

    int ans = 0;
    rep(y, h) rep(x, w)
    {
        ans += dp[a[y][x]];
    }

    cout << ans << endl;

    return 0;
}