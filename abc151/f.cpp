#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

ld dist(pair<ld, ld> p1, pair<ld, ld> p2)
{
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int main()
{
    int n;
    cin >> n;
    vector<pair<ld, ld>> p(n);
    ld max_dist = 0.0;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        p[i] = pair<ld, ld>((ld)x, (ld)y);
    }

    rep(i, n)
    {
        rep(j, n)
        {
            max_dist = max(max_dist, dist(p[j], p[i]));
        }
    }

    cout << max_dist / 2.0 << endl;

    return 0;
}