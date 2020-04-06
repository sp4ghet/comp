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
    vint a(n);
    rep(i, n) cin >> a[i];
    vint b;
    int prev = !a[0];
    b.emplace_back(0);
    rep(i, n)
    {
        if (prev != a[i])
        {
            b.back()++;
        }
        else
        {
            b.emplace_back(1);
        }
        prev = a[i];
    }

    int ans = 0;
    int k = b.size();
    rep(i, k)
    {
        int now = 0;
        rep(j, min(3, k - i))
        {
            now += b[i + j];
        }
        ans = max(ans, now);
    }

    cout << ans << endl;

    return 0;
}