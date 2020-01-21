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
    int n;
    cin >> n;
    ll ans = 0;
    vector<vector<ll>> counts(10, vector<ll>(10, 0));
    for (int i = 1; i <= n; ++i)
    {
        int k = i;
        int lower = i % 10;
        int digits = (int)log10(i);
        k = (int)(k / pow(10, digits));

        counts[k][lower]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            ans += counts[i][j] * counts[j][i];
        }
    }

    cout << ans << endl;

    return 0;
}