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
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> g(h);
    rep(y, h)
    {
        cin >> g[y];
    }

    ll ans = INT32_MAX;
    rep(j, (1 << h - 1))
    {
        int loc = __builtin_popcount(j);

        ll now = loc;
        vector<vector<int>> lines(loc + 1, vector<int>(w + 1));
        int i = 0;
        rep(y, h)
        {
            rep(x, w)
            {
                lines[i][x + 1] += (g[y].at(x) == '1');
            }
            if (j & (1 << y))
            {
                i++;
            }
        }
        rep(y, loc + 1) rep(x, w) lines[y][x + 1] += lines[y][x];

        bool ok = true;
        int cutx = 0;
        rep(x, w)
        {
            rep(y, loc + 1)
            {
                if (lines[y][x + 1] - lines[y][cutx] > k)
                {
                    if (lines[y][x] - lines[y][cutx] > k)
                    {
                        ok = false;
                    }
                    cutx = x;
                    now++;
                }
            }
        }
        if (!ok)
            continue;

        // bitset<5> b = j;
        // cout << b << " " << now << endl;
        // view(lines);

        ans = min(now, ans);
    }

    cout << ans << endl;

    return 0;
}