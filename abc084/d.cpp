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

struct sieve
{
    int n;
    vector<int> f, primes;

    sieve(int n = 1) : n(n), f(n + 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (f[i])
                continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = (ll)i * (ll)i; j <= n; j += i)
            {
                if (!f[j])
                    f[j] = i;
            }
        }
    }

    bool isPrime(int x)
    {
        return f[x] == x;
    }
};

int main()
{
    int Q;
    cin >> Q;
    int largest = 0;
    vector<P> q(Q);
    rep(i, Q)
    {
        cin >> q[i].first >> q[i].second;
        largest = max(largest, q[i].second);
    }
    sieve s(largest);
    vector<int> simCount(largest + 1);
    for (int i = 3; i <= largest; i += 2)
    {
        simCount[i] = simCount[i - 2];
        simCount[i - 1] = simCount[i - 2];
        if (s.isPrime(i) && s.isPrime((i + 1) / 2))
        {
            simCount[i]++;
        }
    }

    rep(i, Q)
    {
        cout << (simCount[q[i].second] - simCount[q[i].first - 1]) << endl;
    }

    return 0;
}