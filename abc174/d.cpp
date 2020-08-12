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

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cr = 0;
    rep(i, n) cr += s[i] == 'R' ? 1 : 0;
    int cw = n - cr;
    int wtr = 0, rtw = 0;
    rep(i, n)
    {
        if (i < cr)
        {
            if (s[i] == 'W')
                wtr++;
        }
        if (i >= cr)
        {
            if (s[i] == 'R')
                rtw++;
        }
    }
    int ans = max(rtw, wtr);
    cout << ans << endl;
    return 0;
}