#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> sum(n+1, 0);
    rep(i,n){
        cin >> a[i];
        a[i]--;
        sum[i+1] = (sum[i] + a[i]) % k;
    }

    map<int, int> dp;
    queue<int> q;
    ll ans = 0;
    for(int i=0; i <= n; ++i){
        int s = sum[i];
        ans += dp[s];
        dp[s]++;
        q.push(s);
        if(q.size() == k){
            dp[q.front()]--;
            q.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
