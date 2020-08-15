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
template <typename X, typename M>
struct LazySegTree
{
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;

    int n;
    FX fx;
    FA fa;
    FM fm;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    LazySegTree(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_) : n(),
                                                                fx(fx_),
                                                                fa(fa_),
                                                                fm(fm_),
                                                                em(em_),
                                                                ex(ex_)
    {
        n = 1 << (int)(log2(n_) + 1);
        dat = vector<X>(2 * n + 1, ex_);
        lazy = vector<M>(2 * n + 1, em_);
    }
    // 1-indexed
    void set(int i, X x)
    {
        dat[i] = x + n;
    }

    void build()
    {
        for (int i = n - 1; i >= 1; i--)
        {
            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    void eval(int k)
    {
        if (lazy[k] == em)
            return;

        if (k < n)
        {
            lazy[k * 2] = fm(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
        }
        dat[k] = fa(dat[k], lazy[k]);
        lazy[k] = em;
    }

    void update(int a, int b, M m, int k, int l, int r)
    {
        eval(k);
        if (a <= l && b >= r)
        {
            lazy[k] = fm(lazy[k], m);
            eval(k);
        }
        else if (a < r && b > l)
        {
            update(a, b, m, k * 2, l, (l + r) / 2);
            update(a, b, m, k * 2 + 1, (l + r) / 2, r);
            dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    void update(int s, int t, M m)
    {
        update(s, t, m, 1, 0, n);
    }

    X query(int a, int b, int k, int l, int r)
    {
        eval(k);
        if (b <= l || a >= r)
        {
            return ex;
        }
        else if (a <= l && b >= r)
        {
            return dat[k];
        }
        int newK = k * 2;
        X vl = query(a, b, newK, l, (l + r) / 2);
        X vr = query(a, b, newK + 1, (l + r) / 2, r);
        return fx(vl, vr);
    }

    X query(int a, int b)
    {
        return query(a, b, 1, 0, n);
    }
};
#pragma endregion

const int INF = (1LL << 31) - 1;

int main()
{
    int n, q;
    cin >> n >> q;

    auto fx = [](int a, int b) { return min(a, b); };
    auto fa = [](int x, int m) { return m; };
    auto fm = [](int a, int b) { return b; };
    LazySegTree<int, int> st(n, fx, fa, fm, INF, INF);
    rep(i, q)
    {
        int com, s, t, x;
        cin >> com >> s >> t;
        if (com == 0)
        {
            // update
            cin >> x;
            st.update(s, t + 1, x);
        }
        else
        {
            int ans = st.query(s, t + 1);
            cout << ans << endl;
        }
    }

    return 0;
}