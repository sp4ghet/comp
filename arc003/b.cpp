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
    cin >> n;
    vector<string> s(n);
    rep(i, n)
    {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());
    rep(i, n)
    {
        reverse(s[i].begin(), s[i].end());
        cout << s[i] << endl;
    }

    return 0;
}