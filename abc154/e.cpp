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

int dp[105][4][2];

int main()
{
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();
    dp[0][0][0] = 1;

    rep(i, n) rep(j, 4) rep(k, 2)
    {
        int nd = s.at(i) - '0';
        rep(d, 10)
        {
            int ni = i + 1, nj = j + min(d, 1), nk = k;
            if (nj > K)
                continue;
            if (nk == 0)
            {
                if (d > nd)
                    continue;
                if (d < nd)
                    nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];

    cout << ans << endl;
    return 0;
}