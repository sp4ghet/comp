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
    int n, m;
    cin >> n >> m;
    int l = (n + 1) * (n + 1);
    vector<int> p(n + 1);
    rep(i, n) cin >> p[i + 1];
    vector<int> q(l);
    rep(i, n + 1) rep(j, n + 1)
    {
        q[j + i * (n + 1)] = p[i] + p[j];
    }
    sort(q.begin(), q.end());

    int ans = 0;
    rep(i, l)
    {
        int k = m - q[i];

        int qp = lower_bound(q.begin(), q.end(), k) - q.begin();
        qp--;

        int now = q[qp] + q[i];
        if (now > m)
        {
            continue;
        }
        ans = max(ans, now);
    }

    cout << ans << endl;

    return 0;
}