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
    int n, w;
    cin >> n >> w;

    vector<vector<int>> t(n, vector<int>(2));
    rep(i, n){
        cin >> t[i][0] >> t[i][1];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));

    rep(i, n){
        int m = t[i][0], //mass
            v = t[i][1]; //value
        for(int j=0; j <= w; j++){
            if(j-m < 0){
                dp[i+1][j] = dp[i][j];
                continue;
            }
            dp[i+1][j] = max(dp[i][j], dp[i][j-m] + v);
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
