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

int main()
{
    int n, m;
    cin >> n >> m;
    vvint p(n + 2, vint(n + 2));
    rep(_, m)
    {
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--;
        p[a][b]++;
        p[a + x + 1][b + x + 2]++;
        p[a + x + 2][b + 1]++;
        p[a][b + 1]--;
        p[a + x + 2][b + x + 2]--;
        p[a + x + 1][b]--;
    }
    // view(p);

    vvint c(n + 2, vint(n + 2));
    rep(y, n) rep(x, n)
    {
        c[y][x + 1] = c[y][x] + p[y][x];
    }
    // cout << "right:\n";
    // view(c);
    rep(y, n) rep(x, n)
    {
        c[y + 1][x] += c[y][x];
    }
    // cout << "down:\n";
    // view(c);

    rep(y, n) rep(x, n)
    {
        c[y + 1][x + 1] += c[y][x];
    }
    // cout << "diag:\n";
    // view(c);

    int ans = 0;
    rep(y, n) rep(x, n)
    {
        if (c[y][x + 1])
            ans++;
    }

    cout << ans << endl;

    return 0;
}