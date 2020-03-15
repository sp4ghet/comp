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
    ll a, b, c;
    cin >> a >> b >> c;
    ll k = (c - a - b);
    bool ans = k * k > 4LL * a * b;
    if (k < 0)
    {
        ans = false;
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}