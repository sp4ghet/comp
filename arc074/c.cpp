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

#define rep(i, n) for (ll i = 0; i < n; ++i)
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
    ll w, h;
    cin >> w >> h;
    ll ans = 1e11;
    rep(_, 2)
    {
        rep(x, w)
        {
            ll s1 = x * h;
            ll remx = w - x;
            ll s2 = remx * (h / 2);
            ll s3 = remx * (h - h / 2);
            ll diff = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
            s2 = h * (remx / 2);
            s3 = h * (remx - remx / 2);
            ll diff2 = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
            diff = min(diff, diff2);
            ans = min(ans, diff);
        }

        swap(w, h);
    }

    cout << ans << endl;

    return 0;
}