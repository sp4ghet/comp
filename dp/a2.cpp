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

vector<int> dp;
vector<int> h;
#define INF INT32_MAX
int hop(int i)
{
    if (dp[i] < INF)
        return dp[i];
    if (i == 0)
        return 0;

    int optimal = INF;
    chmin(optimal, hop(i - 1) + abs(h[i] - h[i - 1]));
    if (i > 1)
        chmin(optimal, hop(i - 2) + abs(h[i] - h[i - 2]));

    return dp[i] = optimal;
}

int main()
{
    int n;
    cin >> n;
    h = vector<int>(n);
    dp = vector<int>(n + 1, INF);
    rep(i, n) cin >> h[i];

    int ans = hop(n - 1);

    cout << ans << endl;

    return 0;
}