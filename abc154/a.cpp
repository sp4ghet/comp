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
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if (u == s)
    {
        cout << (a - 1) << " " << b << endl;
    }
    else
    {
        cout << a << " " << (b - 1) << endl;
    }
    return 0;
}