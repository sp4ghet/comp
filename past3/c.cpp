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

ll a, r, n;
const ll INF = 1e9;

int main()
{
    cin >> a >> r >> n;
    n--;
    ll x = r, ret = 1, nth = a;

    while (n)
    {
        if (n & 1)
        {
            ret *= x;
        }

        if (a * ret > INF || x > INF)
        {
            cout << "large" << endl;
            return 0;
        }

        n >>= 1;
        x *= x;
    }

    nth = a * ret;
    if (nth > INF)
    {
        cout << "large" << endl;
        return 0;
    }

    cout << nth << endl;

    return 0;
}