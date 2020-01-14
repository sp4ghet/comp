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
    int n, k, m;
    cin >> n >> k >> m;
    int sum = 0;
    int a;
    rep(i, n - 1)
    {
        cin >> a;
        sum += a;
    }
    int tot = m * n;
    int ans = tot - sum;
    if (ans > k)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << max(0, ans) << endl;
    }

    return 0;
}