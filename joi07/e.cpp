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
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    rep(i, r) rep(j, c) cin >> a[i][j];

    int ans = 0;
    rep(x, 1 << r)
    {
        int now = 0;
        rep(j, c)
        {
            int ok = 0;
            rep(i, r)
            {
                bool flip = a[i][j];
                if ((1 << i) & x)
                {
                    flip = !flip;
                }
                if (flip)
                {
                    ok++;
                }
            }
            now += max(r - ok, ok);
        }
        ans = max(ans, now);
    }

    cout << ans << endl;

    return 0;
}