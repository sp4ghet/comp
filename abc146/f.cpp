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
    int n, m;
    string s;
    cin >> n >> m >> s;

    const int INF = 1 << 30;
    // num steps to win
    vector<int> dp(n+1, INF);
    dp[n] = 0;

    // num steps to win in reachable area
    queue<int> q;
    q.push(0);
    for(int i=n-1; i >=0; --i){
        while(true){
            if(q.size() == 0){
                cout << "-1" << endl;
                return 0;
            }
            // if furthest reachable block is winnable, take
            if(q.front() != INF &&  q.size() <= m) break;
            // if queue is longer than m, q.front() is not reachable
            // if q.front() is INF, q.front() is not winnable
            q.pop();
        }
        // if s[i] is not winnable, ignore
        if(s[i] == '0') dp[i] = q.front()+1;

        // add current block to queue
        q.push(dp[i]);
    }

    vector<int> ans;
    int x = 0;
    int moves = dp[0];
    while(x < n){
        --moves;
        int i=1;
        while(dp[x+i] != moves) i++;
        ans.push_back(i);
        x += i;
    }

    view(ans);

     return 0;
}
