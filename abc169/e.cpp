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

int main()
{
    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll low, high;
    if (n % 2 == 0)
    {
        rep(i, n)
        {
            a[i] *= 2;
            b[i] *= 2;
        }
        low = (a[n / 2] + a[n / 2 - 1]) / 2;
        high = (b[n / 2] + b[n / 2 - 1]) / 2;
    }
    else
    {
        low = a[n / 2];
        high = b[n / 2];
    }

    ll ans = high - low + 1;
    cout << ans << endl;

    return 0;
}