#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < n; ++i)
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
    // 出発点に戻らなきゃいけない！
    // 気づかず時間を溶かした

    int INF = 1 << 25;

    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, INF));
    rep(i, e)
    {
        int f, t, c;
        cin >> f >> t >> c;
        g[f][t] = c;
    }
    vector<vector<int>> dp(1LL << v, vector<int>(v, INF));

    // Since it is a loop, we can start at any arbitrary position.
    // Thus, we can start ONLY at 0 (at the bitset 000...01)
    // This way, we can detect the shortest loop by choosing the path which ends at some vertex, and comes back to 0
    dp[1][0] = 0;

    rep(i, 1LL << v)
    {
        rep(j, v)
        {
            // Is node j contained in current set i?
            bool in = (i & (1LL << j)) != 0LL;

            if (!in)
                continue;

            // generate set without j
            ll prev = i ^ (1LL << j);

            rep(f, v)
            {
                // is f in prev?
                bool inPrev = ((1LL << f) & prev) != 0LL;

                if (!inPrev)
                    continue;

                if (g[f][j] == -1)
                    continue;

                chmin(dp[i][j], dp[prev][f] + g[f][j]);
            }
        }
    }

    int ans = INF;
    rep(i, v)
    {
        chmin(ans, dp[(1LL << v) - 1][i] + g[i][0]);
    }

    if (ans == INF)
        ans = -1;

    cout << ans << endl;

    return 0;
}