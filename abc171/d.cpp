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
    map<int, int> m;
    rep(i, n)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    ll ans = 0;
    for (auto p : m)
    {
        ans += p.first * p.second;
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        ll b, c;
        cin >> b >> c;
        ll cnt = m[b];
        m[c] += cnt;
        m[b] = 0;
        ans -= b * cnt;
        ans += c * cnt;

        cout << ans;
        if (i != q - 1)
        {
            cout << '\n';
        }
    }
    cout << endl;

    return 0;
}