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
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, cols;
    cin >> n >> cols;
    vvint d(cols, vint(cols)), c(n, vint(n));
    rep(i, cols) rep(j, cols) cin >> d[i][j];
    rep(i, n) rep(j, n)
    {
        cin >> c[i][j];
        c[i][j]--;
    }
    map<int, int> m1, m2, m3;
    rep(i, n) rep(j, n)
    {
        int k = (i + j) % 3;
        int now = c[i][j];
        if (k == 0)
            m1[now]++;
        if (k == 1)
            m2[now]++;
        if (k == 2)
            m3[now]++;
    }

    ll ans = 1LL << 60;
    rep(c1, cols) rep(c2, cols) rep(c3, cols)
    {
        if (c1 == c2 || c2 == c3 || c3 == c1)
        {
            continue;
        }
        ll now = 0;
        for (P p : m1)
        {
            now += d[p.first][c1] * p.second;
        }
        for (P p : m2)
        {
            now += d[p.first][c2] * p.second;
        }
        for (P p : m3)
        {
            now += d[p.first][c3] * p.second;
        }

        chmin(ans, now);
    }

    cout << ans << endl;

    return 0;
}