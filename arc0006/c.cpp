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
    vector<int> piles(n, INT32_MAX);
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    int ans = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            if (piles[j] >= w[i])
            {
                if (piles[j] == INT32_MAX)
                {
                    ans++;
                }
                piles[j] = w[i];
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}