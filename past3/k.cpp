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

int main()
{
    int n, q;
    cin >> n >> q;
    vint c(n), d(n), p(n);
    rep(i, n)
    {
        // current parent
        c[i] = -(i + 1);
        // tail of table
        d[i] = i + 1;
        p[i] = -(i + 1);
    }

    rep(i, q)
    {
        int f, x, t;
        cin >> f >> t >> x;
        f--;
        x--;
        t--;

        int tail = d[f];
        d[f] = c[x];
        p[d[f]] = -f;
        p[x] = -t;
        p[tail] = -t;
        c[x] = d[t];
        d[t] = tail;
    }

    rep(i, n)
    {
        int tb = c[i] >= 0 ? c[i] - 1 : c[i];
        vint v;
        while (tb >= 0)
        {
            v.emplace_back(tb);
            tb = c[tb] >= 0 ? c[tb] - 1 : c[tb];
        }
        for (int a : v)
        {
            c[a] = tb;
        }
        tb = -tb;

        cout << tb << "\n";
    }

    cout << endl;

    return 0;
}