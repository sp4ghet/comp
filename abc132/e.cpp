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

const int INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vvint g(n, vint());
    rep(i, m)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f].emplace_back(t);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;

    queue<P> q;
    vvint cst(n, vint(3, INF));
    q.push(P(s, 0));
    cst[s][0] = 0;
    while (q.size())
    {
        P p = q.front();
        q.pop();
        int v = p.first, cmod = p.second;
        if (v == t && cmod == 0)
        {
            break;
        }
        int c = cst[v][cmod];
        int nc = (c + 1) % 3;
        for (int nv : g[v])
        {
            if (cst[nv][nc] > c + 1)
            {
                cst[nv][nc] = c + 1;
                q.push(P(nv, nc));
            }
        }
    }

    int ans = cst[t][0];
    if (ans == INF)
    {
        ans = -3;
    }
    cout << (ans / 3) << endl;

    return 0;
}