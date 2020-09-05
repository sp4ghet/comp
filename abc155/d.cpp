#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vll = vector<ll>;
#define _GLIBCXX_DEBUG

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

const ll INF = INT64_MAX - 5;

int main()
{
    ll n, k;
    cin >> n >> k;
    vll pos, neg, zer;
    rep(i, n)
    {
        ll a;
        cin >> a;
        if (a == 0)
        {
            zer.emplace_back(a);
        }
        else if (a > 0)
        {
            pos.emplace_back(a);
        }
        else
        {
            neg.emplace_back(abs(a));
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    auto cnt = [&](ll x) {
        ll now = 0;
        if (x == 0)
        {
            now = neg.size() * pos.size();
            return now;
        }
        if (x > 0)
        {

            rep(i, pos.size())
            {
                // (a,b]
                ll fd = (x - 1) / pos[i];
                int idx = upper_bound(pos.begin(), pos.end(), fd) - pos.begin();
                if (idx > i)
                    idx--;
                now += max(0, idx);
            }
            rep(i, neg.size())
            {
                ll fd = (x - 1) / neg[i];
                int idx = upper_bound(neg.begin(), neg.end(), fd) - neg.begin();
                if (idx > i)
                    idx--;
                now += max(0, idx);
            }
            now /= 2;

            now += neg.size() * pos.size();
            now += zer.size() * (pos.size() + neg.size());
            now += (zer.size() * (zer.size() - 1)) / 2;

            return now;
        }
        // x < 0
        x = abs(x);
        rep(i, pos.size())
        {
            ll fd = (x) / pos[i];
            int idx = upper_bound(neg.begin(), neg.end(), fd) - neg.begin();
            now += neg.size() - idx;
        }
        return now;
    };

    ll l = -INF, r = INF;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        ll c = cnt(mid);
        // printf("%ld %ld: %ld %ld\n", l, r, mid, c);
        bool ok = c < k;
        if (ok)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    printf("%ld\n", l);

    return 0;
}