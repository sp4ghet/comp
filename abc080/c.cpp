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

bool chmax(int &a, int b)
{
    if (b >= a)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<bitset<10>> f(n);
    rep(i, n) rep(j, 10)
    {
        int a;
        cin >> a;
        f[i].set(j, a);
    }
    vvint p(n, vint(11));
    rep(i, n) rep(j, 11) cin >> p[i][j];

    int ans = INT32_MIN;
    for (int i = 1; i < 1024; i++)
    {
        bitset<10> b = i;
        int score = 0;
        rep(j, n)
        {
            int c = (f[j] & b).count();
            score += p[j][c];
        }
        chmax(ans, score);
    }

    cout << ans << endl;

    return 0;
}