#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#pragma region Debug

istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

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

ll INF = 1LL << 60;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<P>> r(n, vector<P>(n, P(INF, 0)));
    rep(i, m)
    {
        ll s, g, d, t;
        cin >> s >> g >> d >> t;
        s--;
        g--;
        r[s][g] = P(d, t);
        r[g][s] = P(d, t);
    }

    vector<vector<P>> dp(1LL << n, vector<P>(n, P(INF, 0)));
    dp[1][0] = P(0, 1);

    rep(i, 1LL << n)
    {
        rep(j, n)
        {
            bool in = ((1LL << j) & i) != 0;
            if (!in)
                continue;

            ll prev = i ^ (1LL << j);

            rep(f, n)
            {
                bool inPrev = ((1LL << f) & prev) != 0;
                if (!inPrev)
                    continue;

                ll nowDist = dp[prev][f].first + r[f][j].first;
                // road is closed already or closes while traversing
                if (nowDist > r[f][j].second)
                    continue;

                if (dp[i][j].first > nowDist)
                {
                    dp[i][j] = P(nowDist, dp[prev][f].second);
                }
                else if (dp[i][j].first == nowDist)
                {
                    dp[i][j].second += dp[prev][f].second;
                }
            }
        }
    }

    // view(dp);

    P ans = P(INF, 0);
    rep(i, n)
    {
        P now = dp[(1LL << n) - 1][i];

        ll curDist = now.first + r[i][0].first;
        // road closed on return trip or closes on return trip
        if (curDist > r[i][0].second)
            continue;

        if (ans.first > curDist)
        {
            ans = P(now.first + r[i][0].first, now.second);
        }
        else if (ans.first == curDist)
        {
            ans.second += now.second;
        }
    }

    if (ans.first == INF || ans.second == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}