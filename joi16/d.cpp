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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> c;
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
        c[a[i]]++;
    }

    // cumulative sum of each type
    // taking a range [l, r] (1-indexed) `cs[r] - cs[l]`
    // gives you the number of that type in the range
    vvint cs(m, vint(n + 1));

    rep(i, m) rep(j, n)
    {
        cs[i][j + 1] = cs[i][j] + (a[j] == i);
    }

    vint dp(1 << m, 1 << 25);
    dp[0] = 0;

    rep(i, 1 << m)
    {
        int start = 0;
        rep(j, m)
        {
            if ((1 << j) & i)
                start += c[j];
        }

        // assume all items in S have been placed to the left
        // choose the item which has to do the least moving and place it on the right
        rep(j, m)
        {
            // if the type is already in the set, skip
            bool in = ((1 << j) & i) != 0;
            if (in)
                continue;

            int unionSet = i | (1 << j);

            int moveJ = c[j] - cs[j][start + c[j]] + cs[j][start];

            chmin(dp[unionSet], dp[i] + moveJ);
        }
    }

    cout << dp[(1 << m) - 1] << endl;

    return 0;
}