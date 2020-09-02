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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vint l(n);
    rep(i, n) cin >> l[i];

    int ans = 5000;
    rep(i, 1 << n)
    {
        int li = 0;

        int cnt = __builtin_popcount(i);
        if (!cnt)
            continue;
        rep(x, n)
        {
            if (!(i & (1 << x)))
                continue;
            li += l[x];
        }

        int cstA = (cnt - 1) * 10 + abs(li - a);

        rep(j, 1 << n)
        {
            if (i & j)
                continue;

            cnt = __builtin_popcount(j);
            if (!cnt)
                continue;
            int lj = 0;
            rep(y, n)
            {
                if (!(j & (1 << y)))
                    continue;
                lj += l[y];
            }
            int cstB = (cnt - 1) * 10 + abs(lj - b);

            rep(k, 1 << n)
            {
                if ((i & k) || (j & k))
                    continue;
                cnt = __builtin_popcount(k);
                if (!cnt)
                    continue;
                int lk = 0;
                rep(z, n)
                {
                    if (!(k & (1 << z)))
                        continue;
                    lk += l[z];
                }
                int cstC = (cnt - 1) * 10 + abs(lk - c);

                ans = min(ans, cstA + cstB + cstC);
            }
        }
    }

    cout << ans << endl;

    return 0;
}