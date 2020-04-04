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

struct sphere
{
    double x, y, z, r;
    sphere(double xx = 0, double yy = 0, double zz = 0, double rr = 0) : x(xx), y(yy), z(zz), r(rr) {}
    double dist(sphere &other)
    {
        double dx = x - other.x, dy = y - other.y, dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz) - r - other.r;
    }
    bool intersect(sphere &other)
    {
        return dist(other) < 0;
    }
};

struct edge
{
    int s, t;
    double d;
    edge(int ss, int tt, double dd) : s(ss), t(tt), d(dd) {}
    bool operator>(const edge &r) const { return d > r.d; }
};

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<sphere> p(n);
        UnionFind uft(n);
        rep(i, n) cin >> p[i].x >> p[i].y >> p[i].z >> p[i].r;
        priority_queue<edge, vector<edge>, greater<edge>> q;
        rep(i, n) rep(j, n)
        {
            if (p[i].intersect(p[j]))
            {
                uft.unite(i, j);
            }
            else
            {
                q.push(edge(i, j, p[i].dist(p[j])));
            }
        }

        long double ans = 0;
        while (q.size())
        {
            edge e = q.top();
            q.pop();
            if (uft.unite(e.s, e.t))
            {
                ans += e.d;
            }
        }

        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}