//https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_a
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
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];
    vll cs(n + 1);
    rep(i, n) cs[i + 1] = cs[i] + a[i];

    for (int i = 1; i <= n; i++)
    {
        ll now = 0;
        for (int j = 0; j <= n - i; ++j)
        {
            now = max(now, cs[j + i] - cs[j]);
        }
        cout << now << endl;
    }

    return 0;
}