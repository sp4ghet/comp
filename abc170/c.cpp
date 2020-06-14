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
    int x, n;
    cin >> x >> n;
    if (n == 0)
    {
        cout << x << endl;
        return 0;
    }
    vint p(n);
    rep(i, n) cin >> p[i];
    int cur = -1000;
    int ans = 0;
    rep(i, 102)
    {
        int d = abs(i - x);
        int dnow = abs(x - cur);
        if (d < dnow && find(p.begin(), p.end(), i) == p.end())
        {
            ans = i;
            cur = i;
        }
    }

    cout << ans << endl;

    return 0;
}