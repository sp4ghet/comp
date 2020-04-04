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
    edge(int ss = 0, int tt = 0, int dd = 0) : s(ss), t(tt), d(dd) {}
    bool operator>(const edge &r) const { return d > r.d; }
};

struct town
{
    int x, y, i;
    town(int xx = 0, int yy = 0, int ii = 0) : x(xx), y(yy), i(ii) {}
};

int INF = 1 << 30;

int main()
{
    int n;
    cin >> n;
    vector<town> xs(n), ys(n);
    rep(i, n)
    {
        cin >> xs[i].x >> xs[i].y;
        xs[i].i = i;
        ys[i] = xs[i];
    }
    sort(xs.begin(), xs.end(), [](town a, town b) { return a.x > b.x; });
    sort(ys.begin(), ys.end(), [](town a, town b) { return a.y > b.y; });

    priority_queue<edge, vector<edge>, greater<edge>> q;
    rep(i, n - 1)
    {
        edge x(xs[i].i, xs[i + 1].i, abs(xs[i].x - xs[i + 1].x)),
            y(ys[i].i, ys[i + 1].i, abs(ys[i].y - ys[i + 1].y));

        q.push(x);
        q.push(y);
    }

    UnionFind uft(n);
    ll ans = 0;
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        if (uft.unite(e.s, e.t))
        {
            ans += e.d;
        }
    }

    cout << ans << endl;

    return 0;
}