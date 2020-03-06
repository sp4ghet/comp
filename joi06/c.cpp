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
    vector<P> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());
    int ans = 0;
    rep(i, n) for (int j = i + 1; j < n; ++j)
    {
        int l = pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2);

        P x = p[i];
        P y = p[j];
        int deltax = (x.first - y.first);
        int deltay = (x.second - y.second);
        P cand1 = P(x.first + deltay, x.second - deltax);
        P cand2 = P(x.first - deltay, x.second + deltax);
        P cand3 = P(y.first + deltay, y.second - deltax);
        P cand4 = P(y.first - deltay, y.second + deltax);
        bool ur = false, ul = false, lr = false, ll = false;

        if (binary_search(p.begin(), p.end(), cand1))
        {
            ur = true;
        }
        if (binary_search(p.begin(), p.end(), cand2))
        {
            ul = true;
        }
        if (binary_search(p.begin(), p.end(), cand3))
        {
            lr = true;
        }
        if (binary_search(p.begin(), p.end(), cand4))
        {
            ll = true;
        }

        if (ur && lr)
        {
            ans = max(ans, l);
        }
        if (ul && ll)
        {
            ans = max(ans, l);
        }
    }

    cout << ans << endl;

    return 0;
}