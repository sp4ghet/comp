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
#pragma region chminmax
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

ll sc(ll nowx, ll nowy, ll nowz, ll x, ll y, ll z)
{
    return abs(nowx + x) + abs(nowy + y) + abs(nowz + z);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    ll ans = 0;
    rep(i, 8)
    {
        vector<ll> v(n);

        // cout << i << endl;
        // cout << ((i & 1) == 1) << (i & 2) << (i & 4) << endl;

        rep(j, n)
        {
            ll s = 0;
            if ((i & 4) == 4)
            {
                s += x[j];
            }
            else
            {

                s -= x[j];
            }
            if ((i & 2) == 2)
            {

                s += y[j];
            }
            else
            {

                s -= y[j];
            }
            if ((i & 1) == 1)
            {
                s += z[j];
            }
            else
            {
                s -= z[j];
            }
            v[j] = s;
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        ll sum = 0;
        rep(k, m)
        {
            sum += v[k];
        }
        chmax(ans, sum);
    }

    cout << ans << endl;

    return 0;
}