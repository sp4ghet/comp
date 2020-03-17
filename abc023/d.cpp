#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int n;
vector<P> b;
vector<double> a;

bool tooSmall(ll x)
{
    rep(i, n)
    {
        if (x < b[i].first)
            return true;

        a[i] = (double)(x - b[i].first) / b[i].second;
    }
    sort(a.begin(), a.end());

    rep(i, n)
    {
        if (a[i] < i)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    cin >> n;
    b = vector<P>(n);
    a = vector<double>(n);

    ll mh = 0, ms = 0;
    rep(i, n)
    {
        cin >> b[i].first >> b[i].second;
        mh = max(mh, b[i].first);
        ms = max(ms, b[i].second);
    }

    ll l = 0, r = mh + ms * n;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (tooSmall(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}