#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int ans = 0;
    for(int i=n-1; i > -1; i--){
        for(int j=n-1; j > -1; j--){
            if(s.at(i) == s.at(j)){
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }else{
                dp[i][j] = 0;
            }
            if(i < j){
                int now = min(j-i, dp[i][j]);
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;
}
