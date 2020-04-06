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

const int p = 100000;

int main()
{
    int n, m;
    cin >> n >> m;
    vint d(n);
    rep(i, n - 1)
    {
        cin >> d[i + 1];
        d[i + 1] += d[i];
    }
    ll ans = 0;
    int now = 0;
    rep(i, m)
    {
        int a;
        cin >> a;
        ans += abs(d[now + a] - d[now]) % p;
        ans %= p;
        now = now + a;
    }

    cout << ans << endl;

    return 0;
}