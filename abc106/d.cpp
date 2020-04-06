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
    int n, m, q;
    cin >> n >> m >> q;
    vvint a(n, vint(n));
    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        a[l][r]++;
    }
    vvint c(n + 1, vint(n + 1));
    rep(i, n) rep(j, n)
    {
        c[i + 1][j + 1] = c[i + 1][j] + c[i][j + 1] - c[i][j] + a[i][j];
    }

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = c[r][r] - c[l][r] - c[r][l] + c[l][l];
        cout << ans << endl;
    }

    return 0;
}