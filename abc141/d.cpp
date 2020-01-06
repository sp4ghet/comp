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
    int n,m;
    cin >> n >> m;

    priority_queue<int> a;
    rep(i, n){
        int a_i;
        cin >> a_i;
        a.push(a_i);
    }

    rep(i, m){
        int now = a.top(); a.pop();
        now /= 2;
        a.push(now);
    }

    ll cost = 0;
    rep(i, n){
        int now = a.top(); a.pop();
        cost += now;
    }

    cout << cost << endl;

    return 0;
}
