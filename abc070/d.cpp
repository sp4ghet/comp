#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, ll>;
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

const ll INF = 1e16;
int main()
{
    int n;
    cin >> n;
    vvp g(n);
    rep(i, n - 1)
    {
        int f, t, d;
        cin >> f >> t >> d;
        f--, t--;
        g[f].emplace_back(P(t, d));
        g[t].emplace_back(P(f, d));
    }

    int qry, k;
    cin >> qry >> k;
    k--;
    vll d(n, INF);
    queue<int> q;
    q.push(k);
    d[k] = 0;

    while (q.size())
    {
        int v = q.front();
        q.pop();
        ll now = d[v];
        for (P p : g[v])
        {
            int nv = p.first;
            ll dist = p.second;
            if (now + dist < d[nv])
            {
                q.push(nv);
                d[nv] = now + dist;
            }
        }
    }

    rep(i, qry)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << d[x] + d[y] << "\n";
    }
    cout << endl;

    return 0;
}
