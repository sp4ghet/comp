// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vp = vector<P>;
using vvp = vector<vp>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;

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
    int n, k;
    cin >> n >> k;
    vp c(n);
    rep(i, n)
    {
        cin >> c[i].first >> c[i].second;
    }

    ll INF = 1LL << 50;
    vvint roads(n, vint());
    vvll g(n, vll(n, INF));
    rep(i, k)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        roads[f].emplace_back(t);
        roads[t].emplace_back(f);
    }

    // construct new graph edges
    rep(i, n)
    {
        queue<int> q;
        q.push(i);
        vll d(n, INF);
        d[i] = 0;
        while (q.size())
        {
            int nv = q.front();
            q.pop();
            if (d[nv] >= c[i].second)
                break;

            for (int t : roads[nv])
            {
                bool update = chmin(d[t], d[nv] + 1);
                if (update)
                {
                    chmin(g[i][t], (ll)c[i].first);
                    q.push(t);
                }
            }
        }
    }
    rep(i, n) g[i][i] = 0;

    vll d(n, INF);
    priority_queue<P, vp, greater<P>> q;
    q.push(P(0, 0));
    d[0] = 0;
    while (q.size())
    {
        P now = q.top();
        q.pop();
        int nv = now.second, cost = now.first;

        rep(j, n)
        {
            if (g[nv][j] == INF)
                continue;

            bool update = chmin(d[j], d[nv] + g[nv][j]);
            if (update)
                q.push(P(g[nv][j], j));
        }
    }

    cout << d[n - 1] << endl;

    return 0;
}