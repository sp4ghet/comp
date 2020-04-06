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

const int n = 1e6 + 1;
int c[n + 1];

int main()
{
    int m;
    cin >> m;
    rep(_, m)
    {
        int l, r;
        cin >> l >> r;
        r++;
        c[l]++;
        c[r]--;
    }

    int ans = 0;
    int now = 0;
    rep(i, n + 1)
    {
        now = now + c[i];
        ans = max(ans, now);
    }

    cout << ans << endl;

    return 0;
}