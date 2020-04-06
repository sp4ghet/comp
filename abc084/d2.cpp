#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vp = vector<P>;
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
    int q;
    cin >> q;
    vp qs(q);
    rep(i, q) cin >> qs[i];
    int n = 0;
    rep(i, q)
    {
        n = max(n, qs[i].second);
    }

    vint p(n + 1);
    p[0] = -1;
    for (int i = 2; i <= n; ++i)
    {
        if (p[i])
            continue;

        p[i] = i;
        for (ll j = (ll)i * i; j <= n; j += i)
        {
            p[j] = i;
        }
    }
    auto isPrime = [&](int x) { return p[x] == x; };
    vint l(n + 1);
    rep(i, n)
    {
        l[i + 1] = l[i];
        if (i % 2)
            continue;
        l[i + 1] += isPrime(i + 1) && isPrime((i + 2) / 2);
    }

    for (P lr : qs)
    {
        cout << l[lr.second] - l[lr.first - 1] << endl;
    }

    return 0;
}