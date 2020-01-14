#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int ans = 1;
    int n = 0;
    ans = a * n - n + 1;
    while (ans < b)
    {
        n++;
        ans = a * n - n + 1;
    }

    cout << n << endl;

    return 0;
}