#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

template <typename T>

void view(const std::vector<T> &v)
{
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
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
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e13;

int main()
{
    int n, m;
    cin >> n >> m;
    vvint g(n, vint());
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int s, k;
    cin >> s >> k;
    s--;
    vint t(k + 1);
    t[0] = s;
    rep(i, k)
    {
        cin >> t[i + 1];
        t[i + 1]--;
    }

    vvll g2(k + 1, vll(k + 1));

    rep(i, k + 1)
    {
        queue<int> q;
        q.push(t[i]);
        vint v(n, INT32_MAX);
        v[t[i]] = 0;
        while (q.size())
        {
            int fr = q.front();
            q.pop();
            for (int to : g[fr])
            {
                bool update = chmin(v[to], v[fr] + 1);
                if (update)
                    q.push(to);
            }
        }

        rep(j, k + 1)
        {
            g2[i][j] = v[t[j]];
        }
    }

    vvll dp((1 << k) + 1, vll(k + 1, INF));
    rep(i, k)
    {
        dp[(1 << i)][i] = g2[0][i + 1];
    }

    rep(j, 1 << k) rep(i, k)
    {
        bool isIn = (j & (1 << i)) != 0;
        if (!isIn)
            continue;
        int prev = j ^ (1 << i);

        rep(l, k)
        {
            bool inPrev = (prev & (1 << l)) != 0;
            if (!inPrev)
                continue;

            chmin(dp[j][i], dp[prev][l] + g2[l + 1][i + 1]);
        }
    }

    // bitset<4> b;
    // rep(i, (1 << k) + 1)
    // {
    //     b = i;
    //     cout << b << ":";
    //     rep(j, k + 1)
    //     {
    //         if (dp[i][j] == INF)
    //             cout << "u ";
    //         else
    //             cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    ll ans = INF;
    for (ll x : dp[(1 << k) - 1])
    {
        chmin(ans, x);
    }

    cout << ans << endl;

    return 0;
}