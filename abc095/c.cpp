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
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if (2 * c < a + b)
    {
        while (x > 0 && y > 0)
        {
            ans += 2 * c;
            x--;
            y--;
        }
    }
    while (x > 0)
    {
        ans += min(2 * c, a);
        x--;
    }
    while (y > 0)
    {
        ans += min(2 * c, b);
        y--;
    }

    cout << ans << endl;

    return 0;
}