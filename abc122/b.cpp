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
    string s;
    cin >> s;
    vector<int> dp(s.size() + 1);
    rep(i, s.size())
    {
        char c = s.at(i);
        bool ok = c == 'A' || c == 'T' || c == 'C' || c == 'G';
        dp[i + 1] = (ok ? dp[i] + 1 : 0);
    }
    auto ans = max_element(dp.begin(), dp.end());

    cout << ans[0] << endl;

    return 0;
}