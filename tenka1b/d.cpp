#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

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

// intervals, and number n
//  2 3 4  5  6
// 1 3 6 10 15 21

// n == 6
// 1,2,3
// 1,4,5
// 2,4,6
// 3,5,6

// n == 10
// 1,2,3,4
// 1,5,6,7
// 2,5,8,9
// 3,6,8,10
// 4,7,9,10

// n == 15
//  1, 2, 3, 4, 5
//  1, 6, 7, 8, 9
//  2, 6,10,11,12
//  3, 7,10,13,14
//  4, 8,11,13,15
//  5, 9,12,14,15

// n == 21
//  1, 2, 3, 4, 5, 6
//  1, 7, 8, 9,10,11
//  2, 7,12,13,14,15
//  3, 8,12,16,17,18
//  4, 9,13,16,19,20
//  5,10,14,17,19,21
//  6,11,15,18,20,21

int main()
{
    int n;
    cin >> n;
    int a = 1;
    int k = 1;
    while (k < n)
    {
        a++;
        k = a * (a + 1) / 2;
    }
    if (k != n)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    // number of sets = a+1;
    cout << a + 1 << endl;

    vint cache;
    int back = 1;
    rep(i, a + 1)
    {
        // size of set == a
        cout << a << " ";
        for (int j = 0; j < cache.size(); j++)
        {
            int c = cache[j];
            cout << c << " ";
            cache[j]++;
        }
        cache.emplace_back(back);
        for (int j = cache.size() - 1; j < a; j++)
        {
            cout << back << " ";
            back++;
        }
        cout << endl;
    }

    return 0;
}