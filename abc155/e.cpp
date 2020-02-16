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
    string s;
    cin >> s;
    // vector<vector<int>> dp(1000000, vector<int>(2));
    ll use = 0, chg = 0;
    int carry = 0;
    rep(i, s.size())
    {
        int k = s.size() - i - 1;
        int n = s.at(k) - '0';
        if ((n + carry) == 10)
        {
            carry = 1;
            continue;
        }

        if ((n + carry) > 5)
        {
            chg += 10 - (n + carry);
            carry = 1;
        }
        else
        {
            use += n + carry;
            carry = 0;
        }
    }
    cout << (use + chg + carry) << endl;

    return 0;
}