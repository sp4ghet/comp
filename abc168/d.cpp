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
        g[t].emplace_back(f);
    }

    queue<int> q;
    q.push(0);
    vint p(n, -1);
    p[0] = 0;
    while (q.size())
    {
        int v = q.front();
        q.pop();
        for (int nv : g[v])
        {
            if (p[nv] != -1)
            {
                continue;
            }
            p[nv] = v;
            q.push(nv);
        }
    }
    cout << "Yes" << endl;
    rep(i, n - 1)
    {
        cout << p[i + 1] + 1 << endl;
    }

    return 0;
}