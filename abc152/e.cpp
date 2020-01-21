#include <bits/stdc++.h>
#include <boost/math/common_factor.hpp>
using namespace std;
typedef unsigned long long ll;
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
const int p = 1e9 + 7; //10^9 + 7
struct mint
{
    ll x;
    mint(ll x = 0) : x(x % p) {}
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= p)
            x -= p;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += p - a.x) >= p)
            x -= p;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= p;
        return *this;
    }

    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const
    {
        if (t == 0)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    mint inv() const
    {
        return pow(p - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
};

// Returns LCM of arr[0..n-1]
unsigned long long int LCM(int arr[], int n)
{
    // Find the maximum value in arr[]
    int max_num = 0;
    for (int i = 0; i < n; i++)
        if (max_num < arr[i])
            max_num = arr[i];

    // Initialize result
    unsigned long long int res = 1;

    // Find all factors that are present in
    // two or more array elements.
    int x = 2; // Current factor.
    while (x <= max_num)
    {
        // To store indexes of all array
        // elements that are divisible by x.
        vector<int> indexes;
        for (int j = 0; j < n; j++)
            if (arr[j] % x == 0)
                indexes.push_back(j);

        // If there are 2 or more array elements
        // that are divisible by x.
        if (indexes.size() >= 2)
        {
            // Reduce all array elements divisible
            // by x.
            for (int j = 0; j < indexes.size(); j++)
                arr[indexes[j]] = arr[indexes[j]] / x;

            res = res * x;
        }
        else
            x++;
    }

    // Then multiply all reduced array elements
    for (int i = 0; i < n; i++)
        res = res * arr[i];

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sm = min();

    ll mult = a[0];
    rep(i, n)
    {
        mult = boost::math::lcm(mult, a[i]);
    }

    mint ans = 0;
    rep(i, n)
    {
        ans += mult / a[i];
    }

    cout << ans.x << endl;

    return 0;
}