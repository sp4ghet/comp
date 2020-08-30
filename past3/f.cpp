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
    vvchar g(n, vchar(n));
    rep(i, n) rep(j, n) cin >> g[i][j];

    vchar ans;
    rep(i, n / 2)
    {
        rep(j, n)
        {
            int ii = n - 1 - i;
            rep(k, n)
            {
                if (g[i][j] == g[ii][k])
                {
                    ans.emplace_back(g[i][j]);
                    break;
                }
            }

            if (ans.size() == i + 1)
                break;
        }
        if (ans.size() != i + 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (char c : ans)
    {
        cout << c;
    }
    if (n % 2)
    {
        cout << g[n / 2][0];
    }
    reverse(ans.begin(), ans.end());
    for (char c : ans)
    {
        cout << c;
    }

    return 0;
}