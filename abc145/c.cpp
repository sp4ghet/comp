#include <bits/stdc++.h>
using namespace std;
using ll = long double;
using P = pair<ll, ll>;

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

ll dist(P a, P b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{

    int n;
    cin >> n;
    vector<P> t(n);
    rep(i, n) cin >> t[i].first >> t[i].second;
    int factorial = 1;
    rep(i, n)
    {
        factorial *= (i + 1);
    }

    sort(t.begin(), t.end());
    ll ans = 0;
    do
    {
        P a = t[0];
        ll now = 0;
        for (int i = 1; i < n; ++i)
        {
            now += dist(a, t[i]);
            a = t[i];
        }
        ans += now;
    } while (next_permutation(t.begin(), t.end()));

    cout.precision(12);
    cout << (ans / factorial) << endl;

    return 0;
}