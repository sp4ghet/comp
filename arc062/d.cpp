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
#pragma region chminmax
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vvp dp(n + 1, vp(2));

    rep(i, n)
    {
        int g = s[i] == 'g' ? 1 : -1;
        P paper = dp[i][0], rock = dp[i][1];
        int pS = paper.first;
        int rS = rock.first;
        int pL = paper.second;
        int rL = rock.second;

        if (pL)
        {
            chmax(dp[i + 1][0], P(pS + g, pL - 1));
        }
        if (rL)
        {
            chmax(dp[i + 1][0], P(rS + g, rL - 1));
        }

        chmax(dp[i + 1][1], P(pS - g, pL + 1));
        chmax(dp[i + 1][1], P(rS - g, rL + 1));
    }

    view(dp);

    return 0;
}