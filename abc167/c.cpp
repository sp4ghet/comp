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
    int n, m, x;
    cin >> n >> m >> x;
    vvint b(n, vint(m + 1));
    rep(i, n) rep(j, m + 1) cin >> b[i][j];

    int ans = INT32_MAX;
    rep(i, 1 << n)
    {
        vint sk(m);
        bool poss = true;
        int now = 0;
        rep(j, n)
        {
            if (((1 << j) & i) == 0)
            {
                continue;
            }

            now += b[j][0];
            rep(k, m)
            {
                sk[k] += b[j][k + 1];
            }
        }
        rep(k, m)
        {
            if (sk[k] < x)
                poss = false;
        }
        if (poss)
        {
            ans = min(now, ans);
        }
    }

    if (ans == INT32_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}