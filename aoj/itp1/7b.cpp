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
    int n = 1, x = 1;
    cin >> n >> x;
    while (n != 0 || x != 0)
    {
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    if (i + j + k == x)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
        cin >> n >> x;
    }
    return 0;
}