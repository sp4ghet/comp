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
    ll n;
    cin >> n;
    vint sq(n + 1);
    rep(i, n + 1) sq[i] = i;

    for (ll i = 1; i <= n; i++)
    {
        int cur = 0;
        int m = ceil(sqrt(i));
        for (int x = 1; x <= m; x++)
        {
            for (int y = 1; y <= m; y++)
            {
                int now = x * x + y * y + x * y;
                now = i - now;
                int z = lower_bound(sq.begin(), sq.end(), now, [&](int a, int b) { return (a * a + a * x + a * y < b); }) - sq.begin();

                if (now && z * z + z * x + z * y == now)
                {
                    cur++;
                }
            }
        }
        cout << cur << endl;
    }

    return 0;
}