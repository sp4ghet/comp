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

int main()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    s[0] = 0;

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] < k)
            continue;

        ll d = s[i] - k;
        int num = lower_bound(s.begin(), s.end(), d) - s.begin();
        if (s[num] == d)
            num++;
        ans += num;
    }
    cout << ans << endl;

    return 0;
}
