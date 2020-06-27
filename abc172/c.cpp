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

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vll sa(n + 1), sb(m + 1);
    rep(i, n) sa[i + 1] = sa[i] + a[i];
    rep(i, m) sb[i + 1] = sb[i] + b[i];
    int ans = 0;

    rep(i, n + 1)
    {
        int books = i;
        ll nowP = sa[i];
        ll nowK = k - nowP;

        if (nowK < 0)
            break;

        int bBooks = upper_bound(sb.begin(), sb.end(), nowK) - sb.begin() - 1;
        bBooks = max(0, bBooks);
        ll bPrice = sb[bBooks];

        if (nowK - bPrice < 0)
            continue;

        chmax(ans, books + bBooks);
    }

    cout << ans << endl;

    return 0;
}