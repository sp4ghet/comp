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
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        b[i] = max(0, a[j] - a[i]);
    }
    b[n] = k - a[n - 1] + a[0];
    sort(b.begin(), b.end());
    ll ans = 0;
    rep(i, n) ans += b[i];
    cout << ans << endl;

    return 0;
}