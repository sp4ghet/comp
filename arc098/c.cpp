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
    vector<int> westCum(n + 1);
    rep(i, n)
    {
        int add = s.at(i) == 'W' ? 1 : 0;
        westCum[i + 1] = add + westCum[i];
    }

    // view(westCum);
    vector<int> flips(n);
    rep(i, n)
    {
        int d = n - i - 1;
        int easts = d - (westCum[n] - westCum[i + 1]);
        flips[i] = westCum[i] + easts;
    }
    int ans = INT32_MAX;
    rep(i, n)
    {
        ans = min(ans, flips[i]);
    }
    cout << ans << endl;
    return 0;
}