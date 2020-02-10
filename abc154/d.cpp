#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
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
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    vector<double> e(n + 1);
    rep(i, n)
    {
        e[i + 1] = e[i] + d[i];
    }

    double maxExp = 0;
    int from, to;
    for (int i = k; i <= n; ++i)
    {
        if (chmax(maxExp, e[i] - e[i - k]))
        {
            from = i - k;
            to = i;
        }
    }
    vector<double> s(1002);
    for (int i = 0; i < 1002; ++i)
    {
        s[i] += s[i - 1] + i;
    }

    double ans = 0;
    for (int i = from; i < to; ++i)
    {
        ans += s[d[i]] / d[i];
    }

    cout << setprecision(8) << ans << endl;

    return 0;
}