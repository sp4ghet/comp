#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
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

int main()
{
    int n, t;
    cin >> n >> t;
    vector<P> d(n);
    // knapsack dp , maximum satisfaction using items 0-i, with time j.
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

    rep(i, n) cin >> d[i].first >> d[i].second;
    // sort list so item i is the most expensive food
    sort(d.begin(), d.end());

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
            chmax(dp[i + 1][j], dp[i][j]);
            int now_time = j + d[i].first;

            if (now_time < t)
                chmax(dp[i + 1][now_time], dp[i][j] + d[i].second);
        }
        // actual best option using items 0-i is knapsack + most expensive food
        int now = dp[i][t - 1] + d[i].second;
        // if this best is better than other options use this item config.
        chmax(ans, now);
    }

    cout << ans << endl;

    return 0;
}