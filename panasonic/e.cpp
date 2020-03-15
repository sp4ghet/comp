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
#pragma region chminmax
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

int main()
{
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    sort(s.begin(), s.end());

    bool d[3][3][2001];

    int ans = 8000;
    do
    {
        rep(i, 3) rep(j, 3) rep(k, s[i].size())
        {
            if (i >= j)
                break;

            bool ok = true;
            for (int ni = k; ni < s[i].size(); ni++)
            {
                int nj = ni - k;
                if (nj >= s[j].size())
                    break;
                if (s[i][ni] == '?' || s[j][nj] == '?')
                    continue;

                if (s[i][ni] != s[j][nj])
                    ok = false;
            }
            d[i][j][k] = ok;
        }

        auto f = [&](int i, int j, int k) {
            if (k >= s[i].size())
                return true;

            return d[i][j][k];
        };

        rep(x, 2001) rep(y, 2001)
        {
            if (!f(0, 1, x))
                continue;
            if (!f(1, 2, y))
                continue;
            if (!f(0, 2, x + y))
                continue;

            int now = 0;
            now = max<int>(now, s[0].size());
            now = max<int>(now, x + s[1].size());
            now = max<int>(now, x + y + s[2].size());
            ans = min(ans, now);
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;

    return 0;
}