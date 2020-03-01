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

const ll INF = 2e9 + 5;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<ll>> dp(v, vector<ll>(v, INF));
    rep(i, e)
    {
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }
    rep(i, v)
    {
        dp[i][i] = 0;
    }

    rep(k, v) rep(i, v) rep(j, v)
    {
        if (dp[i][k] == INF || dp[k][j] == INF)
        {
            continue;
        }
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    rep(i, v)
    {
        if (dp[i][i] < 0)
        {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, v)
    {
        rep(j, v)
        {
            if (j > 0)
            {
                cout << " ";
            }
            if (dp[i][j] == INF)
            {
                cout << "INF";
                continue;
            }
            cout << dp[i][j];
        }
        cout << endl;
    }

    return 0;
}