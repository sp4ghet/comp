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

#pragma region UnionFind
struct UnionFind
{
    vector<int> d;
    // d[x] is the index of the parent of x
    // d[x] is -size if x is a root

    UnionFind(int n) : d(vector<int>(n, -1)) {}
    int root(int x)
    {
        if (d[x] < 0)
        {
            return x;
        }
        return d[x] = root(d[x]);
    }

    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
        {
            return false;
        }
        if (d[x] > d[y])
            swap(x, y); // x always bigger tree

        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    int size(int x) { return -d[root(x)]; }
};
#pragma endregion

struct edge
{
    int s, t, d;
    edge(int ss = -1, int tt = -1, int dd = -1) : s(ss), t(tt), d(dd) {}
    bool operator>(const edge &r) const { return d > r.d; }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<edge, vector<edge>, greater<edge>> q;
    rep(i, m)
    {
        edge e;
        cin >> e.s >> e.t >> e.d;
        e.s--;
        e.t--;
        q.push(e);
    }

    UnionFind uft(n);
    priority_queue<int> rq;
    ll ans = 0;
    int free = n;
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        if (free <= k)
            break;

        if (uft.unite(e.s, e.t))
        {
            ans += e.d;
            free--;
        }
    }
    // rep(i, k - 1)
    // {
    //     rq.pop();
    // }

    // ll ans = 0;
    // while (rq.size())
    // {
    //     ans += rq.top();
    //     rq.pop();
    // }

    cout << ans << endl;

    return 0;
}