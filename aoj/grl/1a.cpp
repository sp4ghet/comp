#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vp = vector<P>;
using vvp = vector<vp>;
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
    int v, e, r;
    cin >> v >> e >> r;
    vvp g(v, vp());
    rep(i, e)
    {
        int f, t, c;
        cin >> f >> t >> c;
        g[f].emplace_back(P(c, t));
    }

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(r);

    ll INF = 1LL << 60;
    vll d(v, INF);
    d[r] = 0;

    while (q.size())
    {
        int nv = q.top();
        q.pop();
        for (P t : g[nv])
        {
            bool update = chmin(d[t.second], d[nv] + t.first);
            if (update)
                q.push(t.second);
        }
    }

    rep(i, v)
    {
        if (d[i] == INF)
        {
            cout << "INF" << endl;
            continue;
        }
        cout << d[i] << endl;
    }

    return 0;
}