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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, 0));
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    rep(i, n) g[i][i] = 1;

    int ans = 0;
    rep(i, 1 << n)
    {
        bool valid = true;
        rep(j, n) rep(k, n)
        {
            bool p = (1 << j) & i;
            p = p && ((1 << k) & i);
            if (p)
            {
                valid = valid && g[j][k];
            }
        }
        if (valid)
        {
            ans = max(ans, __builtin_popcount(i));
        }
    }

    cout << ans << endl;

    return 0;
}