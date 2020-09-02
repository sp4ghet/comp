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

long double z = 0;
int main()
{
    long double n, k;
    cin >> n >> k;
    long double p = max(z, (n - k) / n);
    cout.precision(15);
    // std::cout.setf(std::ios::fixed, std::ios::floatfield);

    long double q = 0.;
    for (ll i = 1; i <= min(k, n); i++)
    {
        long double now = 1.0;
        ll j = i;
        while (j < k)
        {
            j *= 2;
            now /= 2.0;
        }
        // cout << fixed << i << " " << now << endl;
        q += now;
    }
    q /= n;
    p += q;

    cout << fixed << p << endl;

    return 0;
}