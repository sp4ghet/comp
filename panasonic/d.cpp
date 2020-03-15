#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

vector<string> ans;

void rec(int k, string s)
{
    if (k == 1)
    {
        ans.emplace_back(s);
        return;
    }
    char d = 'a';
    rep(i, s.size())
    {
        d = max(d, s.at(i));
    }

    rep(i, d - 'a' + 2)
    {
        char c = 'a' + i;
        string ss = string(1, c);
        rec(k - 1, s + ss);
    }
}

int main()
{
    int n;
    cin >> n;

    rec(n, "a");
    sort(ans.begin(), ans.end());
    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }

    return 0;
}