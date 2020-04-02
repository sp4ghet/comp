// #define _GLIBCXX_DEBUG
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
    int n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;

    vvint g(n + 1, vint());
    vint infected(k);
    rep(i, k)
    {
        cin >> infected[i];
        infected[i]--;
    }

    rep(i, m)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f].emplace_back(t);
        g[t].emplace_back(f);
    }

    ll INF = 1LL << 50;

    vint c(n + 1);
    queue<int> bq;

    vll d(n + 1, INF);
    rep(i, k)
    {
        int bad = infected[i];
        c[bad] = 2;
        g[n].emplace_back(bad);
    }

    bq.push(n);
    d[n] = 0;

    while (bq.size())
    {
        int nv = bq.front();
        bq.pop();
        if (d[nv] > s)
            break;

        for (int t : g[nv])
        {
            bool update = chmin(d[t], d[nv] + 1);
            chmax(c[t], 1);
            if (update)
                bq.push(t);
        }
    }

    // important to use greater<int> here.
    // https://mickey24.hatenablog.com/entry/20090702/1246487222
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    d = vll(n, INF);
    d[0] = 0;

    while (pq.size())
    {
        int nv = pq.top();
        pq.pop();

        for (int t : g[nv])
        {
            // infected
            if (c[t] == 2)
                continue;

            int cost = p;
            // dangerous
            if (c[t] == 1)
                cost = q;

            // you don't need to pay for the shelter
            if (t == n - 1)
                cost = 0;

            bool update = chmin(d[t], d[nv] + cost);
            if (update)
                pq.push(t);
        }
    }

    cout << d[n - 1] << endl;

    return 0;
}