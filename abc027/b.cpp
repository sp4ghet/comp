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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) sum += a[i];
    if (sum % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int avg = sum / n;
    int ans = 0;
    int curSum = 0;
    int curN = 0;
    rep(i, n)
    {
        curSum += a[i];
        curN++;
        if (curSum % curN == 0 && curSum / curN == avg)
        {
            curSum = 0;
            curN = 0;
            continue;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}