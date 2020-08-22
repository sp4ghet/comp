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

int solve(map<int, int> ax, map<int, int> ay, set<P> st)
{
    P mx(0, 0), my(0, 0);
    for (P p : ax)
    {
        if (p.second > mx.second)
        {
            mx = p;
        }
    }
    for (P p : st)
    {
        if (p.second == mx.first)
        {
            ay[p.first]--;
        }
    }
    for (P p : ay)
    {
        // P q = {p.first, mx.first};
        // int sub = st.find(q) != st.end() ? -1 : 0;
        if (p.second > my.second)
        {
            my = p;
        }
    }
    int ans = mx.second + my.second;

    return ans;
}

int main()
{
    int h, w, m;
    cin >> h >> w >> m;

    UnionFind uft(m);
    vp a(m);
    map<int, int> ay, ax;
    set<P> st;
    rep(i, m)
    {
        int y, x;
        cin >> y >> x;
        ay[y]++;
        ax[x]++;
        P p = P(y, x);
        st.emplace(p);
    }

    int ans = solve(ax, ay, st);

    swap(ax, ay);
    set<P> st2;
    for (P p : st)
    {
        swap(p.first, p.second);
        st2.emplace(p);
    }
    ans = max(ans, solve(ax, ay, st2));

    cout << ans << endl;

    return 0;
}

// 011
// 011