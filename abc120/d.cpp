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

int main()
{
    int n, m;
    cin >> n >> m;
    stack<P> es;
    rep(i, m)
    {
        P edge;
        cin >> edge;
        edge.first--;
        edge.second--;
        es.push(edge);
    }
    UnionFind uft(n);
    ll fuck = (ll)n * (n - 1) / 2;
    stack<ll> ans;
    while (es.size())
    {

        ans.push(fuck);
        P e = es.top();
        es.pop();

        ll a = uft.size(e.first), b = uft.size(e.second);
        bool newB = uft.unite(e.first, e.second);
        if (newB)
        {
            fuck -= a * b;
        }
    }

    while (ans.size())
    {
        ll a = ans.top();
        ans.pop();
        cout << a << endl;
    }

    return 0;
}