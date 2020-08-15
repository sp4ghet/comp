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
    cin >> n;
    vint l(n);
    rep(i, n) cin >> l[i];

    int ans = 0;
    rep(i, n) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++)
    {
        if (i == j || j == k || i == k)
            continue;
        if (l[i] == l[j] || l[j] == l[k] || l[i] == l[k])
            continue;

        int c = max(l[i], max(l[j], l[k]));
        int a, b;
        if (c == l[i])
        {
            a = l[j];
            b = l[k];
        }
        else if (c == l[j])
        {
            a = l[i];
            b = l[k];
        }
        else
        { // l[k] = a
            a = l[i];
            b = l[j];
        }

        if (a + b > c)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}