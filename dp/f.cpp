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
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    string s, t;
    cin >> s >> t;

    int sn = s.size();
    int tn = t.size();
    vector<vector<int>> dp(sn + 1, vector<int>(tn + 1));
    dp[0][0] = 0;

    rep(i, sn){
        rep(j, tn){
            if(s[i] == t[j]){
                chmax(dp[i+1][j+1], dp[i][j] + 1);
            }
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    string ans = "";
    int i=sn, j=tn;
    while(i > 0 && j > 0){
        int now = dp[i][j];
        int shaveS = dp[i-1][j];
        int shaveT = dp[i][j-1];
        if(now == shaveS){
            --i;
        }else if(now == shaveT){
            --j;
        }
        else
        {
            ans = s[i-1] + ans;
            --i; --j;
        }
    }

    cout <<  ans <<  endl;

    return 0;
}
