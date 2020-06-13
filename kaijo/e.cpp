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
#pragma region chminmax
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
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

const int MAX_T = 262144 + 5;
map<int, int> dp[55];
map<int, bool> v[55];

int count(vint &a, int i, int now, int n, int t, int s, int prod, int k, bitset<50> usage)
{
    if (i == n)
    {
        return (now == t && prod == s && usage.count() <= k);
    }

    if (v[i][usage.to_ulong()])
    {
        return dp[i][usage.to_ulong()];
    }

    v[i][usage.to_ulong()] = true;

    return dp[i][usage.to_ulong()] = count(a, i + 1, now, n, t, s, prod, k, usage) + count(a, i + 1, (now | a[i]), n, t, s, (prod & a[i]), k, usage.set(i, true));
}

int main()
{
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vint a(n);
    rep(i, n) cin >> a[i];
    int max_a = (1 << 19) - 1;

    ll ans = count(a, 0, 0, n, t, s, max_a, k, 0);
    rep(i, n) for (auto p : dp[i])
    {
        dp[i + 1][p.first] = dp[i][p.first];
        dp[i + 1][p.first | 1 << i] += dp[i][p.first]
    }

    cout << ans << endl;

    return 0;
}