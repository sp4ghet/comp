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

int main()
{
    int n;
    string s;
    cin >> n >> s;
    ll w = 0;
    rep(i, n) w += (s[i] == '.');
    ll ans = INT32_MAX;
    ll b = 0;
    rep(i, n)
    {
        ans = min(ans, b + w);
        b += (s[i] == '#');
        w -= (s[i] == '.');
    }

    ans = min(ans, b + w);
    cout << ans << endl;

    return 0;
}