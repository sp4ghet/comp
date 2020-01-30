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

vector<int> dp(100005, -1);
vector<vector<int>> g(100005, vector<int>());

int dfs(int v)
{
    if (dp[v] != -1)
    {
        return dp[v];
    }
    int maxLen = 0;
    for (int child : g[v])
    {
        chmax(maxLen, dfs(child) + 1);
    }

    return dp[v] = maxLen;
}

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        g[from].emplace_back(to);
    }
    int ans = 0;
    rep(i, n)
    {
        chmax(ans, dfs(i));
    }

    cout << ans << endl;

    return 0;
}