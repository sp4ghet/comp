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

#pragma region Segment Tree
template <typename X>
struct SegTree
{
    using FX = function<X(X, X)>;

    int n;
    FX f, u;
    const X id;
    vector<X> dat;
    SegTree(int n_, FX f_, FX u_, X id_) : n(), f(f_), u(u_), id(id_)
    {
        n = 1 << (int)(log2(n_) + 1);
        dat = vector<X>(2 * n + 1, id_);
    }
    void set(int i, X x)
    {
        dat[i] = x + n;
    }
    void build()
    {
        for (int i = n - 1; i >= 1; i--)
        {
            dat[i] = f(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    // update according to u(dat[i],x);
    void update(int i, X x)
    {
        int k = i + n;
        dat[k] = u(dat[k], x);
        while (k / 2)
        {
            k /= 2;
            dat[k] = f(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    X query(int a, int b, int k, int l, int r)
    {
        if (a <= l && b >= r)
        {
            return dat[k];
        }
        else if (b <= l || a >= r)
        {
            return id;
        }
        int newK = k * 2;
        X vl = query(a, b, newK, l, (l + r) / 2);
        X vr = query(a, b, newK + 1, (l + r) / 2, r);
        return f(vl, vr);
    }

    // query according to reduce([a,b), f, id)
    X query(int a, int b)
    {
        return query(a, b, 1, 0, n);
    }
};
#pragma endregion

int main()
{

    return 0;
}