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
    int unopen = 0;
    int unclosed = 0;
    string ans;
    ans.assign(s.begin(), s.end());
    for (char c : s)
    {
        if (c == ')' && unclosed <= 0)
        {
            unopen++;
        }
        if (c == '(')
        {
            unclosed++;
        }
        if (c == ')' && unclosed > 0)
        {
            unclosed--;
        }
    }
    rep(i, unopen)
    {
        ans = "(" + ans;
    }
    rep(i, unclosed)
    {
        ans += ")";
    }
    cout << ans << endl;
    return 0;
}