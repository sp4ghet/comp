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

#define INF 10e9 + 7

int main()
{
    int n, w;
    cin >> n >> w;

    vector<vector<ll>> t(n, vector<ll>(2));
    int max_v = 0;
    rep(i, n){
        cin >> t[i][0] >> t[i][1];
        max_v += t[i][1];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(max_v+1, INF));

    dp[0][0] = 0;

    rep(i, n){
        ll m = t[i][0];
        ll v = t[i][1];
        for(int j=0; j <= max_v; j++){

            if(j-v >= 0) chmin(dp[i + 1][j], dp[i][j-v] + m);

            chmin(dp[i+1][j], dp[i][j]);

        }
    }

    int ans = 0;
    for(int i=0; i <= max_v; i++){
        if(dp[n][i] <= w) ans = i;
    }

    cout <<  ans << endl;

    return 0;
}
