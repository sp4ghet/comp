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
    int a, b;
    cin >> a >> b;

    int ans = -1;
    rep(i, 1005)
    {
        int acand = floor((float)i * 0.08);
        int bcand = floor((float)i * 0.1);

        if (a == acand && b == bcand)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}