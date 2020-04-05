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
    int k;
    cin >> k;

    vll a;
    rep(i, 9) a.emplace_back(i + 1);
    int back = 0;
    while (a.size() <= k)
    {
        int curSize = a.size();
        for (int i = back; i < curSize; i++)
        {
            ll x = a[i];
            a.emplace_back(x * 10 + (x % 10));
            if (x % 10 != 9)
            {
                a.emplace_back(x * 10 + (x % 10) + 1);
            }

            if (x % 10 != 0)
            {
                a.emplace_back(x * 10 + (x % 10) - 1);
            }
        }
        back = curSize;
    }

    a.emplace_back(0);

    sort(a.begin(), a.end());

    cout << a[k] << endl;

    return 0;
}