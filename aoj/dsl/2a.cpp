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

struct segtree
{
    int n, INF;
    vint dat;
    segtree(int count, int start)
    {
        int c = 1 << (int)(log2(count) + 1);
        n = c;
        INF = start;
        dat = vint(2 * c, INF);
    }

    void update(int i, int x)
    {
        int k = i + n;
        dat[k] = x;
        while (k / 2)
        {
            k /= 2;
            dat[k] = min(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    int subGetMin(int a, int b, int k, int l, int r)
    {
        // out
        if (b <= l || a >= r)
        {
            return INF;
        }
        // completely contained
        if (a <= l && b >= r)
        {
            return dat[k];
        }
        // partially contained
        // call child
        int newK = k * 2;
        int vl = subGetMin(a, b, newK, l, (l + r) / 2);
        int vr = subGetMin(a, b, newK + 1, (l + r) / 2, r);
        return min(vl, vr);
    }

    int getMin(int a, int b)
    {
        return subGetMin(a, b, 1, 0, n);
    }
};

int main()
{

    const int INF = (1LL << 31) - 1;
    int n, q;
    cin >> n >> q;
    segtree st(n, INF);
    rep(i, q)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t)
        {
            int m = st.getMin(x, y + 1);
            cout << m << endl;
        }
        else
        {
            st.update(x, y);
        }
    }
    return 0;
}